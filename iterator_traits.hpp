/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:09:00 by mmounib           #+#    #+#             */
/*   Updated: 2022/09/26 16:09:07 by mmounib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_CONTAINERS_ITERATOR_TRAITS_HPP
#define FT_CONTAINERS_ITERATOR_TRAITS_HPP

#include <iostream>

//#include <iterator>

namespace ft {

    template<class Iter>
    class iterator_traits {
    public:
        typedef typename Iter::value_type value_type;
        typedef typename Iter::difference_type difference_type;
        typedef typename Iter::reference reference;
        typedef typename Iter::pointer pointer;
        typedef typename Iter::iterator_category iterator_category;
    };

    template<class T>  class iterator_traits<T *> {
    public:
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T &reference;
        typedef T *pointer;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template<class T>
    class iterator_traits<const T *> {
    public:
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef const T &reference;
        typedef const T *pointer;
        typedef std::random_access_iterator_tag iterator_category;
    };
}

#endif //FT_CONTAINERS_ITERATOR_TRAITS_HPP
