/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:09:37 by mmounib           #+#    #+#             */
/*   Updated: 2022/10/30 10:09:54 by mmounib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

#include "vector.hpp"

namespace ft {

    template<class T, class Container = ft::vector<T> > class stack {

    public:
        typedef             Container                                   container_type;
        typedef             T                                           value_type;
        typedef typename    container_type::size_type                   size_type;
        typedef typename    container_type::reference                   reference;
        typedef typename    container_type::const_reference             const_reference;

        // Stack ConStructor

        explicit stack(const Container& cont = Container()) : _container(cont) {}

        // Member Functions

        bool empty() const { return (_container.empty()); }

        size_type size() const { return (_container.size()); }

        value_type &top() { return (_container.back()); }
        const value_type &top() const { return (_container.back()); }

        void push (const value_type& val) { _container.push_back(val); }

        void pop() { _container.pop_back(); }

        template <class I, class Con>  friend bool operator== (const stack<I,Con>& lhs, const stack<I,Con>& rhs);

        template <class I, class Con>  friend bool operator<  (const stack<I,Con>& lhs, const stack<I,Con>& rhs);

        template <class I, class Con>  friend bool operator!= (const stack<I,Con>& lhs, const stack<I,Con>& rhs);

        template <class I, class Con>  friend bool operator<  (const stack<I,Con>& lhs, const stack<I,Con>& rhs);

        template <class I, class Con>  friend bool operator<= (const stack<I,Con>& lhs, const stack<I,Con>& rhs);

        template <class I, class Con>  friend bool operator>  (const stack<I,Con>& lhs, const stack<I,Con>& rhs);

        template <class I, class Con>  friend bool operator>= (const stack<I,Con>& lhs, const stack<I,Con>& rhs);

    protected:
        container_type _container;
    };

    // Non Member Functions

    template <class I, class Con>  bool operator== (const stack<I,Con>& lhs, const stack<I,Con>& rhs) { return (lhs._container == rhs._container); }

    template <class I, class Con>  bool operator!= (const stack<I,Con>& lhs, const stack<I,Con>& rhs) { return (lhs._container != rhs._container); }

    template <class I, class Con>  bool operator<  (const stack<I,Con>& lhs, const stack<I,Con>& rhs) { return (lhs._container < rhs._container); }

    template <class I, class Con>  bool operator<= (const stack<I,Con>& lhs, const stack<I,Con>& rhs) { return (lhs._container <= rhs._container); }

    template <class I, class Con>  bool operator>  (const stack<I,Con>& lhs, const stack<I,Con>& rhs) { return (lhs._container > rhs._container); }

    template <class I, class Con>  bool operator>= (const stack<I,Con>& lhs, const stack<I,Con>& rhs) { return (lhs._container >= rhs._container); }
}
#endif //FT_CONTAINERS_STACK_HPP
