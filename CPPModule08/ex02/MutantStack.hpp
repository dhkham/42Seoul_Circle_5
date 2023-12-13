/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:42:14 by dkham             #+#    #+#             */
/*   Updated: 2023/12/13 20:42:15 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <iterator>
#include <iostream>

// Template class MutantStack, inheriting from std::stack (template class means it can be used with any type)
template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Default constructor: uses the constructor of std::stack
    MutantStack() : std::stack<T>() {}

    // Parameterized constructor: adds a single element (e.g., MutantStackM<int> mstack(42);)
    MutantStack(const T& value) : std::stack<T>() {
        std::cout << "MutantStack: parameterized constructor" << std::endl;
        this->push(value);
    }

    // Copy constructor: uses the copy constructor of std::stack
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}

    // Copy assignment operator: checks for self-assignment, then uses the assignment operator of std::stack
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }

    // Virtual destructor: ensures proper cleanup if class is further derived
    virtual ~MutantStack() {}

    // Type definitions for iterator and const_iterator
    // These are derived from the container type used by the underlying std::stack
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    // Method to get an iterator to the beginning of the stack
    iterator begin() { return std::stack<T>::c.begin(); }

    // Method to get an iterator to the end of the stack
    iterator end() { return std::stack<T>::c.end(); }

    // Const-qualified method to get a const_iterator to the beginning of the stack
    const_iterator begin() const { return std::stack<T>::c.begin(); }

    // Const-qualified method to get a const_iterator to the end of the stack
    const_iterator end() const { return std::stack<T>::c.end(); }
};

#endif
