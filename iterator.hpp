/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:07:17 by mmounib           #+#    #+#             */
/*   Updated: 2022/10/15 15:07:24 by mmounib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_ITERATOR_HPP
#define FT_CONTAINERS_ITERATOR_HPP
//#include <stack>

#include "iterator_traits.hpp"

namespace ft {

    template<class I>

    class iterator {
    public :
        typedef         I                                           iterator_type;
        typedef typename iterator_traits<I>::value_type             value_type;
        typedef typename iterator_traits<I>::difference_type        difference_type;
        typedef typename iterator_traits<I>::reference              reference;
        typedef typename iterator_traits<I>::pointer                pointer;
        typedef typename iterator_traits<I>::iterator_category      iterator_category;

        iterator() {}

        iterator(iterator_type ptr) : _it(ptr) {}

        ~iterator() {}

        template<typename T> iterator(const iterator<T> &cst) { *this = cst; }

        template <typename T> iterator &operator=(const iterator<T> &op) { this->_it = op.base(); return (*this);}

        template<typename T> bool operator==(const iterator<T> &it1) const { return (this->_it == it1.base()); }

        template<typename T> bool operator!=(const iterator<T> &it1) const { return (this->_it != it1.base()); }

        template<typename T> bool operator>(const iterator<T> &it1) const { return (this->_it > it1.base()); }

        template<typename T> bool operator<(const iterator<T> &it1) const { return (this->_it < it1.base()); }

        template<typename T> bool operator<=(const iterator<T> &it1) const { return (this->_it <= it1.base()); }

        template<typename T> bool operator>=(const iterator<T> &it1) const { return (this->_it >= it1.base()); }

        reference operator*() const { return (*_it); }

        pointer operator->() const { return (_it); }

        iterator &operator++() {
            _it++;
            return (*this);
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++_it;
            return (temp);
        }

        iterator &operator--() {
            _it--;
            return (*this);
        }

        iterator operator--(int) {
            iterator temp = *this;
            --_it;
            return (temp);
        }

        iterator operator+(difference_type n) const {return (this->_it + n);}
//        difference_type operator+(const iterator& it) const {return (this->_it + );}

        iterator& operator+=(difference_type n) {
            this->_it += n;
            return (*this);
        }

        iterator operator-(difference_type n) const {return (this->_it - n);}

        iterator& operator-=(difference_type n) {
            this->_it -= n;
            return (*this);
        }

        reference operator[](difference_type n) const
        {
            return (_it[n]);
        }

        iterator_type base() const {return (this->_it);}

    private :
        iterator_type _it;

    };

    template<class I, class W> typename iterator<I>::difference_type operator-(const iterator<I>& lhs, const iterator<W>& rhs) {return (lhs.base() - rhs.base());}

    template<class I> typename iterator<I>::pointer operator+(const typename iterator<I>::difference_type n, const iterator<I>& it) {return (it.base() + n);}
}



#endif //FT_CONTAINERS_ITERATOR_HPP
