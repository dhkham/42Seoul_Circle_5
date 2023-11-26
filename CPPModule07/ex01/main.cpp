/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:49:29 by dkham             #+#    #+#             */
/*   Updated: 2023/11/26 19:02:30 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

/*
    printElement, incrementElement: 템플릿으로 안 써도 되는 것인지 확인
    
    Your iter function template must work with any type of array. The third parameter can be an instantiated function template.
    -> 이 조건 만족하는지 확인
*/
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
