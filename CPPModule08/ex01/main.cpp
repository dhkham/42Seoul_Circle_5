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
    int nums[] = {1, 2, 3, 4, 5};
    std::vector<int> numbers(nums, nums + sizeof(nums) / sizeof(nums[0]));
    sp2.addNumber(numbers.begin(), numbers.end()); // add numbers from vector

    int moreNums[] = {6, 7, 8, 9, 10};
    std::vector<int> moreNumbers(moreNums, moreNums + sizeof(moreNums) / sizeof(moreNums[0]));
    sp2.addNumber(moreNumbers.begin(), moreNumbers.end()); // add more numbers from vector

    try {
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
