/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:49:29 by dkham             #+#    #+#             */
/*   Updated: 2023/11/20 19:49:38 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

// Example function to be used with iter
template<typename T>
void printElement(const T& elem) {
    std::cout << elem << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"Hello", "World", "C++", "Template"};

    std::cout << "Integer Array:" << std::endl;
    iter(intArray, 5, printElement);

    std::cout << "String Array:" << std::endl;
    iter(strArray, 4, printElement);

    return 0;
}
