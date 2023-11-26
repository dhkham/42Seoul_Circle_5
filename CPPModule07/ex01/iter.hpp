/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:49:53 by dkham             #+#    #+#             */
/*   Updated: 2023/11/26 18:09:32 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
/*
Non-const reference version (void (*func)(T&)): 
used with functions that might modify the elements of the array. 
suitable for scenarios where the elements of the array need to be changed.

Const reference version (void (*func)(T const&)): 
for functions that do not modify the elements of the array. 
better choice for read-only operations on the array elements.
*/

// iter: iterates through an array and applies a function to each element
template<typename T>
void iter(T* array, size_t length, void (*func)(T&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template<typename T>
void iter(T* array, size_t length, void (*func)(T const&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif
