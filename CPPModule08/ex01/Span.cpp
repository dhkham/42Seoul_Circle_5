/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:43:06 by dkham             #+#    #+#             */
/*   Updated: 2023/12/22 15:13:27 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// default constructor
Span::Span() : _maxSize(0) {}

// constructor
Span::Span(unsigned int N) : _maxSize(N) {} // set N as the maximum size of the span

// copy constructor
Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize) {}

// copy assignment operator
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

// destructor
Span::~Span() {}

// adds a single number to the span
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::length_error("Span is already full");
    }
    _numbers.push_back(number);
}

// returns the shortest span between any two integers in the span
int Span::shortestSpan() const {
    if (_numbers.size() < 2) { // if there are less than two elements in the span, there is no span
        throw std::logic_error("Not enough elements to find a span");
    }

    std::vector<int> sorted = _numbers;             // copy the vector of numbers
    std::sort(sorted.begin(), sorted.end());        // sort the vector of numbers

    int shortest = std::numeric_limits<int>::max(); // initialize the shortest span to the maximum value of an int
    for (size_t i = 1; i < sorted.size(); ++i) {    // iterate over the sorted vector
        int diff = sorted[i] - sorted[i - 1];       // calculate the difference between the current and previous element
        if (diff < shortest) {                      // if the difference is smaller than the current shortest span
            shortest = diff;                        // update the shortest span
        }
    }
    return shortest;
}

// returns the longest span between any two integers in the span
long long Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough elements to find a span");
    }

    int minElem = *std::min_element(_numbers.begin(), _numbers.end());
    int maxElem = *std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<long long>(maxElem) - static_cast<long long>(minElem);
}

