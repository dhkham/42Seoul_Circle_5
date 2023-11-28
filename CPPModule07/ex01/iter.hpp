/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:49:53 by dkham             #+#    #+#             */
/*   Updated: 2023/11/28 20:18:15 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <ostream>

template <typename T>
void iter(T *array, size_t length, void (*func)(T &)) {
    for (size_t i = 0; i < length; i++)
        func(array[i]);
    std::cout << "non const version" << std::endl;
}

template <typename T>
void iter(const T *array, size_t length, void (*func)(const T &)) {
    for (size_t i = 0; i < length; i++)
        func(array[i]);
    std::cout << "const version" << std::endl;
}

template <typename T>
void printArray(T &element) {
    std::cout << element << std::endl;
}

template <typename T>
void incrementArray(T &element) {
    element++;
}

#endif
