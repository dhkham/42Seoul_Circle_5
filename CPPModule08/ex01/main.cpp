/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:43:01 by dkham             #+#    #+#             */
/*   Updated: 2023/12/22 14:57:03 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main() {
    Span sp = Span(5);  // span of max 5 elements
    sp.addNumber(6);    // add numbers
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try {
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Testing with a large number of elements
    Span largeSpan(10000); // span of max 10000 elements
    for (int i = 0; i < 10000; ++i) {
        largeSpan.addNumber(i * 2); // Add even numbers from 0 (=0*2) to 19998 (=9999*2)
    }
    
    try {
        std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // use template addNumber
    Span sp2 = Span(10);  // span of max 10 elements
    std::vector<int> numbers;
    for (int i = 1; i <= 5; ++i) {
        numbers.push_back(i);
    }
    sp2.addNumber(numbers.begin(), numbers.end()); // add numbers from vector (use template addNumber)

    std::vector<int> moreNumbers;
    for (int i = 6; i <= 10; ++i) {
        moreNumbers.push_back(i);
    }
    sp2.addNumber(moreNumbers.begin(), moreNumbers.end()); // add more numbers from vector (use template addNumber)

    try {
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
