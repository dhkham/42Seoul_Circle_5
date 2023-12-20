/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:55:29 by dkham             #+#    #+#             */
/*   Updated: 2023/12/20 16:42:20 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

// Define a custom exception class that inherits from std::exception
class NotFoundException : public std::exception {
public:
    // Override the what() method to provide a custom error message
    const char* what() const throw() {
        return "Element not found in the container";
    }
};

// Define the easyfind function template, which finds the first occurrence of a value in a container
template <typename T>
typename T::iterator easyfind(T &container, int value) {
    // returns an iterator type that is appropriate for the container T.
    // typename keyword is necessary here because T::iterator is a dependent type (its exact type depends on what T is).
    typename T::iterator it = std::find(container.begin(), container.end(), value); // searches for 'value' in 'container' using std::find

    // Check if the element was not found
    if (it == container.end()) {
        // If the element is not found, throw the NotFoundException
        throw NotFoundException();
    }

    // Return the iterator to the found element
    return it;
}

#endif
