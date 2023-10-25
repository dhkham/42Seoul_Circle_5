/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:55:38 by dkham             #+#    #+#             */
/*   Updated: 2023/10/25 20:21:39 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// default constructor
Bureaucrat::Bureaucrat() {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name), grade(grade) {
    if (grade < 1) {    // if grade is too high or low, throw an exception
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name), grade(other.grade) {}

// copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    // "name" is constant and can't be changed after it's initialized
    grade = other.grade;
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// getter functions
const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

// increment and decrement functions (throws exceptions if grade is too high or low)
void Bureaucrat::incrementGrade() {
    if (grade <= 1) {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150) {
        throw GradeTooLowException();
    }
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade too low!";
}

// operator<< overload: print name and grade of bureaucrat
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
/*
The function takes two parameters: a reference to an std::ostream object (e.g., std::cout) and a reference to a Bureaucrat object (left operand: std::cout, right operand: bureaucrat)
It returns a reference to the std::ostream object, allowing for chained operations.

os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
sends the name of the bureaucrat, then sends the string ", bureaucrat grade " to os and the grade of the bureaucrat to the output stream os.

This returns the std::ostream object that was passed in (e.g., std::cout).
This allows for chained output operations, like std::cout << bureaucrat1 << " and " << bureaucrat2;.

In practice, this overloaded << operator allows for the following usage:
Bureaucrat bob("Bob", 2);
std::cout << bob << std::endl; // Outputs something like "Bob, bureaucrat grade 2" to the console.

->  The std::cout << bob line automatically calls your overloaded operator<<, passing std::cout as the os parameter and bob as the bureaucrat parameter.
    The function then formats and sends the desired output to the console.
*/
