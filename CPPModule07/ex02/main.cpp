#include "Array.hpp"
#include <iostream>

int main() {
    try {
        Array<int> intArray(5);

        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i * 10;
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Copy test
        Array<int> copyArray(intArray);
        copyArray[0] = 100;

        std::cout << "Original: " << intArray[0] << ", Copy: " << copyArray[0] << std::endl;

        // Out of bounds test
        std::cout << intArray[6] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
