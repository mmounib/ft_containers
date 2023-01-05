/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 08:51:52 by mmounib           #+#    #+#             */
/*   Updated: 2022/11/21 08:51:59 by mmounib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP

#include "AvlTree.hpp"
#include "pair.hpp"
#include "mapItreator.hpp"
#include <functional>
#include "type_traits.hpp"
#include "vector.hpp"

namespace ft {

    template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map {
        public:
            typedef Key                                                 key_type;
            typedef T                                                   mapped_type;
            typedef ft::pair<const key_type, mapped_type>               value_type;
            typedef std::size_t                                         size_type;
            typedef std::ptrdiff_t                                      difference_type;
            typedef Compare                                             key_compare;
            typedef Allocator                                           allocator_type;
            typedef typename Allocator::reference                       reference;
            typedef typename Allocator::const_reference                 const_reference;
            typedef typename Allocator::pointer                         pointer;
            typedef typename Allocator::const_pointer                   const_pointer;

            typedef  ft::Tree<Allocator, value_type, Compare>                    base_tree;
            typedef typename ft::Tree<Allocator, value_type, Compare>::Node*     Node;

            // ////////////// Iterators ////////////////////

            typedef ft::mapIterator<Compare, Key, Node ,value_type>   iterator;

            typedef ft::mapIterator<Compare, Key, Node ,const value_type>   const_iterator;

            typedef ft::reverse_iterator<iterator>                      reverse_iterator;

            typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;


        // //////////////// Constructors /////////////////////////////

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(), _base_tree(),  _size
            (0),  _alloc(alloc), _comp(comp)  {}

            template <class InputIterator>  map (InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last, const key_compare& comp  = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(), _base_tree(), _size(0),  _alloc(alloc), _comp(comp)
            {
                this->insert(first, last);
            }

            map (const map& x) : _tree(), _base_tree(), _size(0) {
                *this = x;
            }

            map& operator= (const map& x) {
                if (this != &x) {
                    this->clear();
                    this->_comp = x._comp;
                    this->_alloc = x._alloc;
                    this->insert(x.begin(), x.end());
                }

                return (*this);
            }

            ~map() { }

            // ///////////////////////   VALUE_COMPARE   ////////////////////////////

            class value_compare : public std::binary_function<value_type, value_type, bool> {

                friend class map;
                protected:
                    key_compare comp;
                    value_compare(key_compare c) : comp(c) {}

                public :

                    bool operator() (const value_type& x, const value_type& y) const
                    {
                        return ( comp(x.first, y.first) );
                    }
            };

            // /////////////////////// Member Functions ////////////////////////////

            iterator begin() { return (iterator(_base_tree.minValueAVL_Node(_base_tree.get_root()), NULL)); }

            const_iterator begin() const { return (const_iterator(_base_tree.minValueAVL_Node(_base_tree.get_root()), NULL)); }

            reverse_iterator rbegin() { return (reverse_iterator(end())); }
            const_reverse_iterator rbegin() const { return(const_reverse_iterator(end())); }

            iterator end() { return ( iterator(NULL, _base_tree.maxValueAVL_Node(_base_tree.get_root())) ); }

            const_iterator end() const { return ( const_iterator(NULL, _base_tree.maxValueAVL_Node(_base_tree.get_root())) ); }

            reverse_iterator rend() { return (reverse_iterator(begin())); }
            const_reverse_iterator rend() const { return(const_reverse_iterator(begin())); }

            bool empty() const { return (_size == 0); }

            void clear() {
               this->erase(begin(), end());
               _size = 0;
            }

            allocator_type get_allocator() const { return (_alloc); }

            size_type size() const { return (this->_size); }

            size_type max_size() const { return (get_allocator().max_size()); }

            key_compare key_comp() const { return (key_compare()); }

            value_compare value_comp() const { return (value_compare(key_comp())); }

            size_type count (const key_type& k) const {
                if (this->find(k) == end())
                    return (0);
               return (1);
            }
            
            iterator find (const key_type& k) {
                Node node = _base_tree.root_search(ft::make_pair(k, mapped_type()));

                if (node == NULL)
                    return (this->end());

                return ( iterator(node, NULL) );
            }

            const_iterator find (const key_type& k) const {
                Node node = _base_tree.root_search(ft::make_pair(k, mapped_type()));

                if (node == NULL)
                    return (this->end());

                return ( const_iterator(node, NULL) );
            }

            size_type erase (const key_type& k) {
                if (this->find(k) == end())
                    return (0);
                _base_tree.change_root(ft::make_pair(k, mapped_type()));
                _size--;

                return (1);
            }

            void erase (iterator position) {
                _base_tree.change_root(*position);
                _size--;
            }

            void erase (iterator first, iterator last) {
                ft::vector< key_type > vec;

                while (first != last)
                {
                    vec.push_back(first->first);
                    first++;
                }

                for (size_type i = 0; i < vec.size(); i++)
                    erase(vec[i]);
            }

            ft::pair<iterator,bool> insert (const value_type& val) {

                iterator it = iterator(_base_tree.root_search(val), NULL);

                if (it != end())
                    return (ft::pair<iterator, bool>(it, false));

                Node node = _base_tree.make_root(val);
                _size++;
                return (ft::pair<iterator, bool>(iterator(node, NULL), true));
            }

            iterator insert (iterator position, const value_type& val) {

                (void) position;

                iterator it = this->find(val.first);

                if (it != this->end())
                    return (it);

                iterator it1 = iterator(_base_tree.make_root(val), NULL);
                _size++;
                return (it1);
            }

            template <class InputIterator>  void insert (InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last) {
                while (first != last)
                    this->insert((*first++));
            }

            mapped_type& operator[] (const key_type& k) {
                iterator iter = find(k);
                if (iter == end())
                    this->insert(ft::make_pair(k, mapped_type()));
                iterator it = find(k);
                return (it->second);
            }

            iterator lower_bound (const key_type& k) {
                iterator it = begin();
                iterator it1 = end();

                while (it != it1)
                {
                    if (it->first == k || _comp(k, it->first))
                        break;
                    it++;
                }
                return (it);
            }

            const_iterator lower_bound (const key_type& k) const {
                const_iterator it = begin();
                const_iterator it1 = end();

                while (it != it1)
                {
                    if (it->first == k || _comp(k, it->first))
                        break;
                    it++;
                }
                return (it);
            }

            iterator upper_bound (const key_type& k) {
                Node node = _base_tree.upper_bound(ft::make_pair(k, mapped_type()));

                return (iterator(node, NULL));
            }

            const_iterator upper_bound (const key_type& k) const {
                Node node = _base_tree.upper_bound(ft::make_pair(k, mapped_type()));

                return (const_iterator(node, NULL));
            }

            ft::pair<iterator,iterator> equal_range (const key_type& k) {
                return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
            }

            ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const { return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }


            void swap (map& x) {
                _base_tree.swapTree(x._base_tree);
                std::swap(this->_size, x._size);
            }

    private:
            Node                                                       _tree;
            base_tree                                                  _base_tree;
            size_type                                                  _size;
            allocator_type                                             _alloc;
            key_compare                                                _comp;
            value_type                                                 _pair_value;


    };

    // //////////////////////   Relational Operators   ////////////////////////////

    template <class Key, class T, class Compare, class Alloc>  bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
        if (lhs.size() == rhs.size()) {
            if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
                return (true);
        }
        return (false);
    }

    template <class Key, class T, class Compare, class Alloc>  bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(lhs == rhs)); }

    template <class Key, class T, class Compare, class Alloc>  bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
        if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
            return (true);
        return (false);
    }

    template <class Key, class T, class Compare, class Alloc>  bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(rhs < lhs)); }

    template <class Key, class T, class Compare, class Alloc>  bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (rhs < lhs); }

    template <class Key, class T, class Compare, class Alloc>  bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) { return (!(lhs < rhs)); }

    // swap Function

    template <class Key, class T, class Compare, class Alloc>  void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y) { x.swap(y); }
    
}
#endif //FT_CONTAINERS_MAP_HPP
