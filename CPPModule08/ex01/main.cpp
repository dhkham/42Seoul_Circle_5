#include "Span.hpp"
#include <iostream>

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
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
    Span largeSpan(10000);
    for (int i = 0; i < 10000; ++i) {
        largeSpan.addNumber(i * 2);
    }
    std::cout << "Large span shortest: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Large span longest: " << largeSpan.longestSpan() << std::endl;

    return 0;
}
