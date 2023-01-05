/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmounib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:50:17 by mmounib           #+#    #+#             */
/*   Updated: 2022/12/22 12:50:23 by mmounib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_TYPE_TRAITS_HPP
#define FT_CONTAINERS_TYPE_TRAITS_HPP

#include <iostream>


namespace ft {
    template <class T, T v>
        class integral_constant {
        public:
            static const T value = v;
            typedef T                                 value_type;
            typedef integral_constant<T, v>  type;
    };

    // True_type And False_type

    typedef integral_constant<bool,true> true_type;
    typedef integral_constant<bool,false> false_type;

    // std::is_integral

    template<typename T> struct is_integral : false_type {};

    template<> struct is_integral<bool> : true_type {};
    template<> struct is_integral<int> : true_type {};
    template<> struct is_integral<long int> : true_type {};
    template<> struct is_integral<short int> : true_type {};
    template<> struct is_integral<long long int> : true_type {};
    template<> struct is_integral<unsigned char> : true_type {};
    template<> struct is_integral<unsigned short int> : true_type {};
    template<> struct is_integral<unsigned int> : true_type {};
    template<> struct is_integral<unsigned long int> : true_type {};
    template<> struct is_integral<unsigned long long int> : true_type {};
    template<> struct is_integral<char16_t> : true_type {};
    template<> struct is_integral<char32_t> : true_type {};
    template<> struct is_integral<wchar_t> : true_type {};
    template<> struct is_integral<signed char> : true_type {};


    // std::enable_if Implementation

    template<bool B, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T> { typedef T type; };

}
#endif
