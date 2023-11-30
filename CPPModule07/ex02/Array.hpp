#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
public:
    Array(); // default constructor: creates an empty array
    Array(unsigned int n); // constructor with parameter: creates an array of size n, initialized with default values
    Array(const Array& other); // copy constructor
    Array& operator=(const Array& other); // assignment operator
    ~Array(); // destructor

    T& operator[](unsigned int index); // access element
    const T& operator[](unsigned int index) const; // access element
    unsigned int size() const; // return size of the array

private:
    T* _array;  // pointer to the first element of the array
    unsigned int _size; // number of elements in the array
};

// Implementation

template<typename T>
Array<T>::Array() : _array(NULL), _size(0) {} // construction with no parameter: creates an empty array

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {} // construction with parameter: creates an array of size n, initialized with default values

template<typename T>
Array<T>::Array(const Array<T>& other) : _array(NULL), _size(0) { // copy constructor
    *this = other;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) { // assignment operator
    if (this != &other) {
        delete[] _array;
        _array = new T[other._size]();
        _size = other._size;
        for (unsigned int i = 0; i < _size; ++i) {
            _array[i] = other._array[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array() { // destructor
    delete[] _array;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) { // access element
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _array[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const { // access element
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return _array[index];
}

template<typename T>
unsigned int Array<T>::size() const { // return size of the array
    return _size;
}

#endif
