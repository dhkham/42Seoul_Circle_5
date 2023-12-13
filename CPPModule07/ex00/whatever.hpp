/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:57:40 by dkham             #+#    #+#             */
/*   Updated: 2023/12/13 21:11:03 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

// Swaps the values of two given arguments.
// function template: a function that can operate with generic types
template<typename T>
void swap(T& a, T& b) { // takes two references to objects as parameters
    T temp = a;
    a = b;
    b = temp;
}

// Returns the smallest one. (If the two of them are equal, then it returns the second one)
template<typename T>
T const & min(T const & a, T const & b) { // can accept both const and non-const arguments 
    return (b <= a) ? b : a;
}

// Returns the greatest one. (If the two of them are equal, then it returns the second one)
template<typename T>
T const & max(T const & a, T const & b) {
    return (a <= b) ? b : a;
}

#endif
