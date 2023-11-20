/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:49:29 by dkham             #+#    #+#             */
/*   Updated: 2023/11/20 21:01:11 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

// Example function to be used with iter
template<typename T>
void printElement(T& elem) {
    std::cout << elem << std::endl;
}

template<typename T>
void addOne(T& elem) {
    elem += 1;
}

// const 처리???
int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"Hello", "World", "C++", "Template"};

    std::cout << "Integer Array:" << std::endl;
    iter(intArray, 5, printElement);
    
    std::cout << "Integer Array + 1:" << std::endl;
    iter(intArray, 5, addOne);
    iter(intArray, 5, printElement);

    std::cout << "String Array:" << std::endl;
    iter(strArray, 4, printElement);
    
    return 0;
}
