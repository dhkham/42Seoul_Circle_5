/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:56:29 by dkham             #+#    #+#             */
/*   Updated: 2023/10/25 20:09:06 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat highRank("High Rank", 0);
    } catch (std::exception& e) {
        std::cout << e.what() << '\n';
    } catch (...) // catch all other exceptions
    {
        std::cout << "Unknown exception caught" << '\n';
    }
    /*
    The first try block attempts to create a Bureaucrat object with a grade of 0, which is outside the allowed range.
    This causes a GradeTooHighException to be thrown from the Bureaucrat constructor.
    The catch block following this try block catches exceptions of type std::exception (from which GradeTooHighException is derived), by catching by reference.
    and prints the error message associated with the exception.
    */
    try {
        Bureaucrat lowRank("Low Rank", 151);
    } catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }

    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;  // operator<< overload: print name and grade of bureaucrat
        bob.incrementGrade();           // grade: 2 -> 1
        std::cout << bob << std::endl;
        bob.decrementGrade();           // grade: 1 -> 2
        std::cout << bob << std::endl;
        bob.incrementGrade();           // grade: 2 -> 1
        std::cout << bob << std::endl;
        bob.incrementGrade();           // grade: 1 -> 0 : throws GradeTooHighException
        std::cout << bob << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}
