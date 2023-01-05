/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapItreator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:49:15 by mmounib           #+#    #+#             */
/*   Updated: 2022/12/22 12:49:21 by mmounib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_MAPITREATOR_HPP
#define FT_CONTAINERS_MAPITREATOR_HPP

#include <iostream>
#include "AvlTree.hpp"
#include "iterator_traits.hpp"

namespace ft {
    template <class Comp, class key, class treenode , class pair >

    class mapIterator {

        public:
            typedef Comp                                                         _compare;
            typedef treenode                                                     _node;
            typedef key                                                          key_type;
            typedef pair                                                         value_type;
            typedef std::ptrdiff_t                                               difference_type;
            typedef value_type&                                                  reference;
            typedef value_type*                                                  pointer;
            typedef std::bidirectional_iterator_tag                              iterator_category;


            // /////////////          Constructors         /////////////////


            mapIterator() : dummyNode(), treeNode(),  _cmp(),  _pr() {}

            mapIterator(_node s, _node d_node) : dummyNode(d_node), treeNode(s) {}

            ~mapIterator() {}

            mapIterator(const mapIterator& it) : dummyNode(it.dummyNode), treeNode(it.Base()), _cmp(it._cmp) {}

            operator mapIterator<Comp, key, treenode, const pair>() const {  return (mapIterator<Comp, key, treenode, const pair>(treeNode, dummyNode)); }

            mapIterator &operator=(const mapIterator &op) {
                treeNode = op.Base();
                this->_cmp = op._cmp;
                this->dummyNode = op.dummyNode;

                return (*this);
            }

            // /////////////////       Operator Overloading        ///////////////////////////

            reference operator*() const { return (treeNode->Key); }

            pointer operator->() const { return (&treeNode->Key); }

            treenode Base() const { return (this->treeNode); }

            mapIterator& operator++() {

                treeNode = this->treeNode->get_successor(treeNode);
                return (*this);
            }

        mapIterator operator++(int) {
                mapIterator it(*this);

                this->operator++();

                return (it);
            }

            mapIterator& operator--()
            {
                if (!treeNode && dummyNode)
                {
                    treeNode = dummyNode;
                    dummyNode = NULL;
                }
                else if (treeNode && treeNode->left) {
                    treeNode = treeNode->maxValueAVL_Node2(treeNode->left);
                }
                else if (treeNode) {
                    _node temp = treeNode->parent;
                    while (temp && temp->left && temp->left->Key.first == treeNode->Key.first) {
                        treeNode = temp;
                        temp = temp->parent;
                    }
                    treeNode = temp;
                }
                return (*this);
            }
            mapIterator operator--(int) {
                mapIterator it(*this);

                operator--();

                return (it);
            }

           template<class M> bool operator==(const M& y) { return (this->Base() == y.Base()); }

           template<class M> bool operator!=(const M& y) { return (this->Base() != y.Base()); }


        private:
            _node           dummyNode;  //ROOT
            _node           treeNode;
            _compare        _cmp;
            value_type           _pr;
    };
}
#endif //FT_CONTAINERS_MAPITREATOR_HPP
