/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:55:20 by dkham             #+#    #+#             */
/*   Updated: 2023/12/13 20:55:20 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v; // Create a vector of ints
    v.push_back(1); // Add some elements to the vector
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(v, 3); // declaring an iterator it for a vector of integers and initializing it to the position of the element 3 in the vector v, as found by the easyfind function.
        std::cout << "Found: " << *it << std::endl;     // Print the found element
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 6); 
        std::cout << "Found: " << *it << std::endl;     
    } catch (const std::exception& e) {                 // Catch the exception
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
