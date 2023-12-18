/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:04:49 by dkham             #+#    #+#             */
/*   Updated: 2023/12/18 20:12:48 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T> // declaration of the template class Array (e.g., Array<int>): datatype of certain members (variables or functions) can be specified later when an instance of the class is created
class Array {
public:
    Array();                                // default constructor: creates an empty array
    Array(unsigned int n);                  // constructor with parameter: creates an array of size n, initialized with default values
    Array(const Array& other);              // copy constructor
    Array& operator=(const Array& other);   // assignment operator
    ~Array();                               // destructor

    T& operator[](unsigned int index);              // access element
    const T& operator[](unsigned int index) const;  // access element
    unsigned int size() const;                      // return size of the array

private:
    T* _array;          // pointer to the first element of the array
    unsigned int _size; // number of elements in the array
};

template<typename T>
Array<T>::Array() : _array(NULL), _size(0) {} // construction with no parameter: creates an empty array

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {} // construction with parameter: creates an array of size n, initialized with default values (e.g., 0 for int, 0.0 for double, '\0' for char, etc.)

template<typename T>
Array<T>::Array(const Array<T>& other) : _array(NULL), _size(other._size) { // copy constructor
    if (_size > 0) {
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; ++i) {
            _array[i] = other._array[i];
        }
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) { // copy assignment operator
    if (this != &other) { // if not self-assignment
        delete[] _array; // delete old array
        _array = new T[other._size](); // allocate new array
        _size = other._size; // copy size
        for (unsigned int i = 0; i < _size; ++i) { // copy elements
            _array[i] = other._array[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array() { // destructor
    delete[] _array;
}

// operator[] is overloaded twice: once for non-const objects and once for const objects
template<typename T>
T& Array<T>::operator[](unsigned int index) { // access element (takes non-const object as parameter)
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    //std::cout << "non-const operator[] called" << std::endl;
    return _array[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const { // access element (takes const object as parameter)
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    //std::cout << "const operator[] called" << std::endl;
    return _array[index];
}

template<typename T>
unsigned int Array<T>::size() const { // return size of the array (const is used to avoid that the method modifies the object)
    return _size;
}

#endif
