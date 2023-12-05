#include "Span.hpp"
#include <limits>
#include <cmath>

Span::Span(unsigned int N) : _maxSize(N) {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::length_error("Span is already full");
    }
    _numbers.push_back(number);
}

template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end) {
    while (begin != end) {
        addNumber(*begin);
        ++begin;
    }
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough elements to find a span");
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < shortest) {
            shortest = diff;
        }
    }
    return shortest;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough elements to find a span");
    }

    auto minMax = std::minmax_element(_numbers.begin(), _numbers.end());
    return *minMax.second - *minMax.first;
}
