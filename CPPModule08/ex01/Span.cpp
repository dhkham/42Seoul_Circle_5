/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:43:06 by dkham             #+#    #+#             */
/*   Updated: 2023/12/13 20:43:07 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// default constructor
Span::Span() : _maxSize(0) {}

// constructor
Span::Span(unsigned int N) : _maxSize(N) {}

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
int Span::longestSpan() const {
    if (_numbers.size() < 2) { // if there are less than two elements in the span, there is no span
        throw std::logic_error("Not enough elements to find a span");
    }

    // Define the type for the pair of iterators explicitly
    typedef std::vector<int>::const_iterator const_iter; // const_iter is an alias for std::vector<int>::const_iterator (constant iterator means that the iterator cannot be used to modify the value it points to)
    std::pair<const_iter, const_iter> minMax; // pair holds two const_iter objects: one for the minimum and one for the maximum

    minMax = std::minmax_element(_numbers.begin(), _numbers.end()); // minmax_element returns a pair of iterators: one for the minimum and one for the maximum

    return *minMax.second - *minMax.first; // dereference the iterators to get the longest span
}
