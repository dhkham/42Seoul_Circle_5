#include "Array.hpp"
#include <iostream>

int main() {
    try {
        Array<int> intArray(5); // Array of 5 integers

        std::cout << "original array: " << std::endl;
        for (size_t i = 0; i < intArray.size(); ++i) { // Fill the array with values
            intArray[i] = i * 10; // Set the value at index i
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Copy test
        Array<int> copyArray(intArray); // Copy constructor
        copyArray[0] = 10; // Change the first element of the copy

        std::cout << "copy array: " << std::endl;
        for (size_t i = 0; i < copyArray.size(); ++i) { // Fill the array with values
            std::cout << copyArray[i] << " ";
        }
        std::cout << std::endl;

        // Assignment test
        Array<int> assignArray = intArray; // Assignment operator
        assignArray[0] = 100; // Change the first element of the copy

        std::cout << "assignment array: " << std::endl;
        for (size_t i = 0; i < assignArray.size(); ++i) { // Fill the array with values
            std::cout << assignArray[i] << " ";
        }
        std::cout << std::endl;

        // original array again
        std::cout << "original array: " << std::endl;
        for (size_t i = 0; i < intArray.size(); ++i) { // Fill the array with values
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Out of bounds test
        std::cout << intArray[6] << std::endl; // Should throw an exception
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
