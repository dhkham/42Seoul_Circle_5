#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>

class Span {
public:
    Span(unsigned int N);
    void addNumber(int number);
    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end);
    int shortestSpan() const;
    int longestSpan() const;

private:
    std::vector<int> _numbers;
    unsigned int _maxSize;
};

#endif
