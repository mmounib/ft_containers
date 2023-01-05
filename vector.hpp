/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:55:39 by mmounib           #+#    #+#             */
/*   Updated: 2022/09/24 14:55:49 by mmounib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <iostream>
#include <iterator>
#include <algorithm>
#include <cstddef>
//#include <memory>
#include "iterator.hpp"
#include "type_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft {

    template<class T, class Allocator = std::allocator <T> >

    class vector {

    public :
        typedef T                                                   value_type;
        typedef Allocator                                           allocator_type;
        typedef typename Allocator::reference                       reference;
        typedef typename Allocator::const_reference                 const_reference;
        typedef typename Allocator::pointer                         pointer;
        typedef typename Allocator::const_pointer                   const_pointer;
        typedef ft::iterator<pointer>                               iterator;
        typedef ft::iterator<const_pointer>                         const_iterator;
        typedef ft::reverse_iterator<iterator>                      reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
        typedef std::ptrdiff_t                                      difference_type;
        typedef std::size_t                                         size_type;

        // Constructors

        explicit vector(const Allocator& alloc = Allocator()) : t_vec(NULL), vector_size(0), vector_capacity(0), _alloc(alloc) {
        }
        explicit vector(size_t n, const value_type& value = value_type(), const Allocator& alloc = Allocator()) : t_vec(NULL), vector_size(0), vector_capacity(0), _alloc(alloc) {
            if (n > max_size())
                throw std::length_error("vector");
            assign(n, value);
        }
        template <class InputIterator> vector(InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last, const Allocator& alloc = Allocator()) : t_vec(NULL), vector_size(0) , vector_capacity(0), _alloc(alloc) {
            assign(first, last);
        }

        // copy_constructor

        vector(const vector& x) {
          this->vector_size = x.vector_size;
          this->vector_capacity = x.vector_capacity;
          if (vector_capacity)
            this->t_vec = _alloc.allocate(vector_capacity);

          for (size_type i = 0; i < vector_size; ++i) {
              _alloc.construct(t_vec + i, x.t_vec[i]);
          }
        }

        vector& operator= (const vector& x) {
            assign(x.begin(), x.end());

            return (*this);
        }

        // Destructor

        ~vector() {
            for (size_type i = 0; i < vector_size; i++) {
                _alloc.destroy(&t_vec[i]);
            }
            if (vector_capacity)
                _alloc.deallocate(t_vec, vector_capacity);
        }

        // Vector Functions

        Allocator get_allocator() const {
            return (allocator_type());
        }

        iterator begin() {
            return (iterator(t_vec));
        }
        const_iterator begin() const {
            return (const_iterator(t_vec));
        }

        reverse_iterator rbegin() {
            return (reverse_iterator(iterator(t_vec + vector_size)));
        }
        const_reverse_iterator rbegin() const {
            return (const_reverse_iterator(iterator(t_vec + vector_size)));
        }

        reverse_iterator rend() {
            return (reverse_iterator(t_vec));
        }
        const_reverse_iterator rend() const {
            return (const_reverse_iterator(t_vec ));
        }

        iterator end() {
            return (iterator(t_vec + vector_size));
        }
        const_iterator end() const {
            return (const_iterator(t_vec + vector_size));
        }

        size_type size() const {
            return (vector_size);
        }

        size_type max_size() const {
            return (_alloc.max_size());
        }

        bool empty() const {
            return (vector_size == 0);
        }

        size_type capacity() const {
            return (vector_capacity);
        }

        reference operator[](size_type n) {
            return (t_vec[n]);
        }

        const_reference operator[](size_type n) const {
            return (t_vec[n]);
        }

        reference at(size_type n) {
            if (n >= vector_size)
                throw std::out_of_range("Out Of Range Error");
            return (t_vec[n]);
        }

        const_reference at(size_type n) const {
            if (n >= vector_size)
                throw std::out_of_range("Out Of Range Error");
            return (t_vec[n]);
        }

        reference front() {
            return (t_vec[0]);
        }

        const_reference front() const {
            return (t_vec[0]);
        }

        reference back() {
            return (t_vec[vector_size - 1]);
        }

        const_reference back() const {
            return (t_vec[vector_size - 1]);
        }

        value_type* data() {
            return (t_vec);
        }

        const value_type * data() const {
            return (t_vec);
        }

        void push_back(const value_type& x) {
            if (vector_size == 0)
                 reserve(1);
            else if (vector_size == vector_capacity)
                reserve(2 * vector_capacity);
            _alloc.construct(t_vec + vector_size, x);
            vector_size++;
        }

        iterator insert(iterator position, const value_type& val) {

            difference_type index = position - begin();

            insert(position, 1, val);

            return (begin() + index);
        }

        void insert(iterator position, size_type n, const value_type& val) {

            int s = n;
            if (n > max_size())
                throw std::length_error("vector");
            size_type index = position - begin();

            size_type  m_size = vector_size + n;
            size_type si = vector_size;

            if (m_size > vector_capacity * 2)
                reserve(vector_size + n);
            else if (m_size > vector_capacity)
                reserve(vector_capacity * 2);

            for (size_type i = vector_size; i > index ; i--) {

                if (s-- > 0) {
                    _alloc.construct(t_vec + (i + n - 1), t_vec[i - 1]);
                }
                else {
                    t_vec[i + n - 1] = t_vec[i - 1];
                }
            }

            vector_size += n;

            for (size_type i = 0; i < n; ++i) {
                if (index < si)
                {
                    t_vec[index] = val;
                    index++;
                }
                else {
                    _alloc.construct(t_vec + index, val);
                    index++;
                }
            }
        }

        template <class InputIterator> void insert(iterator position, InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last) {

            size_type index = position - begin();

            vector vec_temp(first, last);

            size_type  range = vec_temp.size();
            size_type m_size = vector_size + range;

            int s = range;
            size_type si = vector_size;

            if (m_size > vector_capacity * 2)
                reserve(vector_size + range);
            else if (m_size > vector_capacity)
                reserve(vector_capacity * 2);
            for (size_type i = vector_size ; i > index; i--) {
                if (s-- > 0)
                    _alloc.construct(t_vec + (i + range - 1), t_vec[i - 1]);
                else
                    t_vec[i + range - 1] = t_vec[i - 1];
            }

            vector_size += range;

            for (size_type i = 0; i < range; i++) {

                if (index < si)
                    t_vec[index++] = vec_temp[i];
                else {
                    _alloc.construct(t_vec + index, vec_temp[i]);
                    index++;
                }
            }
        }

        void pop_back() {
           if (t_vec)
               _alloc.destroy(&t_vec[--vector_size]);
        }

        iterator erase(iterator position) {

            difference_type index = position - begin();

            if (!empty()) {
                    _alloc.destroy(t_vec + index);
                    for (size_type i = index; i < vector_size - 1; i++) {
                        _alloc.construct(t_vec + i, t_vec[i + 1]);
                        _alloc.destroy(t_vec + (i + 1));
                    }
                    vector_size--;
                }
            return (begin() + index);
        }

        iterator erase(iterator first, iterator last) {
            iterator tmp = first;
            difference_type si = last - first;

            if (si == 0)
                return (begin());
            if (!empty()) {
                for (iterator it = first; it != last; it++) {
                    _alloc.destroy(&(*it));
                }
                for (iterator it = last; it < end(); it++) {
                    _alloc.construct(&(*first), *it);
                    *first++;
                    _alloc.destroy(&(*it));
                }
                vector_size -= si;
            }
            return (tmp);
        }

        void resize(size_type n, value_type val = value_type()) {
            if (n < vector_size)
            {
                for (size_type i = n; i < vector_size ; i++) {
                    _alloc.destroy(t_vec + i);
                }
            }
            else if (n > vector_size)
            {
                if (n > vector_capacity) {
                    size_type si = vector_capacity * 2;
                    if (si > n)
                        reserve(si);
                    else
                        reserve(n);
                }
                for (size_type i = vector_size; i < n; ++i) {
                    _alloc.construct(t_vec + i, val);
                }
            }
            vector_size = n;
        }

        void reserve(size_type n) {
            if (n <= vector_capacity)
                return ;

            pointer _array = _alloc.allocate(n);
            size_type _size = vector_size;

            for (size_type i = 0; i < vector_size; i++)
                _alloc.construct(_array + i, t_vec[i]);
            clear();
            if (vector_capacity) {
                _alloc.deallocate(t_vec, vector_capacity);
            }
            vector_capacity = n;

            t_vec = _alloc.allocate(vector_capacity);

            vector_size = _size;
            if(!empty()) {
                for (size_type i = 0; i < _size; i++) {
                   _alloc.construct(t_vec + i, _array[i]);
                }
                for (size_type i = 0; i < _size; i++) {
                    _alloc.destroy(&_array[i]);
                }
            }
            _alloc.deallocate(_array, n);
        }

        void clear() {
            for (size_type i = 0; i < vector_size; ++i) {
                _alloc.destroy(t_vec + i);
            }
            vector_size = 0;
        }

        void assign(size_type  n, const value_type& u) {
            if (n == 0)
                return ;
            clear();
            reserve(n);
            for (size_type i = 0; i < n; ++i) {
                push_back(u);
            }
        }

        template <class InputIterator> void assign(InputIterator first, typename enable_if< !is_integral<InputIterator>::value, InputIterator >::type last) {

            vector vec_temp;
            for (; first != last; first++)
                vec_temp.push_back(*first);
            clear();

            size_t n = vec_temp.size();
            reserve(n);
            for (size_t i = 0; i < n; ++i) {
                _alloc.construct(t_vec + i, vec_temp[i]);
            }
            vector_size = n;
        }

        void swap (vector& x) {

            std::swap(this->t_vec, x.t_vec);
            std::swap(this->vector_size, x.vector_size);
            std::swap(this->vector_capacity, x.vector_capacity);

        }


    private :
        pointer t_vec;
        size_t vector_size;
        size_t vector_capacity;
        allocator_type _alloc;
    };

    // std::equal Implementation

    template <class InputIterator1, class InputIterator2>  bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {

        while (first1 != last1) {
            if (!(*first1 == *first2))
                return (false);
            ++first1;
            ++first2;
        }
        return (true);
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>  bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
        while (first1 != last1)
        {
            if ((!pred(*first1,*first2)))
                return (false);
            *first1++;
            *first2++;
        }
        return (true);
    }

    // std::lexicographical_compare Implementation

    template <class InputIterator1, class InputIterator2>  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {

        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    // Non-Member Functions

    template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
        x.swap(y);
    }

    template <class T, class Alloc>  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
        if (lhs.size() == rhs.size()) {
            if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
                return (true);
        }
        return (false);
    }

    template <class T, class Alloc>  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs == rhs)); }

    template <class T, class Alloc>  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

        if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
            return (true);
        return (false);

    }

    template <class T, class Alloc>  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(rhs < lhs)); }

    template <class T, class Alloc>  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (rhs < lhs); }

    template <class T, class Alloc>  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs < rhs)); }
}

#endif //FT_CONTAINERS_VECTOR_HPP
