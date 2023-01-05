/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:33:31 by mmounib           #+#    #+#             */
/*   Updated: 2022/09/30 09:33:39 by mmounib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"

#include <iostream>

namespace ft {
    template<class iter>

     class reverse_iterator {
     public :
         typedef typename iterator_traits<iter>::value_type                 value_type;
         typedef typename iterator_traits<iter>::difference_type            difference_type;
         typedef typename iterator_traits<iter>::reference                  reference;
         typedef typename iterator_traits<iter>::pointer                    pointer;
         typedef typename iterator_traits<iter>::iterator_category          iterator_category;
         typedef            iter                                            iterator_type;

         // Constructors

         reverse_iterator() : _next() {}

         explicit reverse_iterator(iterator_type it) : _next(it) {}

         template <class U>  reverse_iterator(const reverse_iterator<U>& rev_it) {
             this->_next = rev_it.base();
         }

         reference operator*() const {
             iterator_type tmp = _next;

             return *--tmp;
         }

         pointer operator->() const {
             iterator_type tmp = _next;

             return &(*--tmp);
         }

         reference operator[](difference_type n) const {
            return (*(base() - n - 1));
         }

         reverse_iterator& operator++() {
             --_next;
             return (*this);
         }
         reverse_iterator& operator--() {
             ++_next;
             return (*this);
         }

         reverse_iterator  operator++(int) {
            reverse_iterator rev = *this;

            --(_next);
            return (rev);
         }
         reverse_iterator  operator--(int) {
             reverse_iterator rev = *this;

             ++(_next);

             return (rev);
         }

         reverse_iterator operator+( difference_type n ) const {return (reverse_iterator(this->_next - n));}
         reverse_iterator operator-( difference_type n ) const {return (reverse_iterator(this->_next + n));}

         reverse_iterator& operator+=( difference_type n ) {
             _next -= n;

             return (*this);
         }
         reverse_iterator& operator-=( difference_type n ) {
             _next += n;

             return (*this);
         }

         // Functions

         iterator_type base() const {
             return (this->_next);
         }

     private :
         iter _next;
     };

    template <class Iterator, class Iterator1>
    bool operator==( const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator1>& rhs ) {
        return(lhs.base() == rhs.base());}

    template <class Iterator, class Iterator1>
    bool operator!=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator1>& rhs) { return(lhs.base() != rhs.base()); }

    template <class Iterator, class Iterator1>
    bool operator<(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator1>& rhs) {return(lhs.base() > rhs.base());}

    template <class Iterator, class Iterator1>
    bool operator<=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator1>& rhs) {return(lhs.base() >= rhs.base());}

    template <class Iterator, class Iterator1>
    bool operator>(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator1>& rhs) {return(lhs.base() < rhs.base());}

    template <class Iterator, class Iterator1>
    bool operator>=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator1>& rhs) {return(lhs.base() <= rhs.base());}

    template <class Iter>
    ft::reverse_iterator<Iter> operator+( typename ft::reverse_iterator<Iter>::difference_type n, const ft::reverse_iterator<Iter>& it) {return (ft::reverse_iterator<Iter>(it.base() - n));}

    template< class Iterator, class Iterator1>
    typename ft::reverse_iterator<Iterator>::difference_type operator-(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator1>& rhs) {return (rhs.base() - lhs.base());}

}

// Non_Member Functions



#endif //FT_CONTAINERS_REVERSE_ITERATOR_HPP
