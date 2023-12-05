/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:57:40 by dkham             #+#    #+#             */
/*   Updated: 2023/12/05 19:57:54 by dkham            ###   ########.fr       */
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
T const & min(T const & a, T const & b) { // takes two references to const objects as parameters (const: the value of the object cannot be modified, &: use of references to avoid copying the objects)
    return (b <= a) ? b : a;
}

// Returns the greatest one. (If the two of them are equal, then it returns the second one)
template<typename T>
T const & max(T const & a, T const & b) {
    return (a <= b) ? b : a;
}

#endif
