#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <limits>
#include <cmath>
#include <iostream>

class Span {
public:
    
    Span();                             // default constructor
    Span(unsigned int N);               // constructor
    Span(const Span& other);            // copy constructor
    Span& operator=(const Span& other); // copy assignment operator
    ~Span();                            // destructor

    void addNumber(int number);         // adds a single number to the span

    // adds a range of numbers to the span
    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end) {
        std::cout << "addNumber template used" << std::endl;
        while (begin != end) {
            addNumber(*begin); // Calls the non-template addNumber method
            ++begin;
        }
    }

    int shortestSpan() const;           // returns the shortest span between any two integers in the span
    int longestSpan() const;            // returns the longest span between any two integers in the span
    
private:
    std::vector<int> _numbers;          // vector of numbers in the span
    unsigned int _maxSize;              // maximum size of the vector
};

#endif
