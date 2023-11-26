/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:49:29 by dkham             #+#    #+#             */
/*   Updated: 2023/11/26 18:54:28 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

void printElement(int const& element) {
    std::cout << element << " ";
}

void incrementElement(int& element) {
    element++;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    // Using iter with a function that does not modify the array
    iter(intArray, intArraySize, printElement);
    std::cout << std::endl;

    // Using iter with a function that modifies the array
    iter(intArray, intArraySize, incrementElement);

    // Printing the modified array
    iter(intArray, intArraySize, printElement);
    std::cout << std::endl;

    return 0;
}
