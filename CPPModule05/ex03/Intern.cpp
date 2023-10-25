/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:58:14 by dkham             #+#    #+#             */
/*   Updated: 2023/10/25 18:49:52 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Initialize static arrays
const std::string Intern::formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
const Intern::FormCreator Intern::formCreators[] = {&Intern::createShrubberyCreation, &Intern::createRobotomyRequest, &Intern::createPresidentialPardon}; // Array of form creation functions: contains the addresses of the form creation functions

Intern::Intern() {} // Default constructor

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other; // The other intern's state is irrelevant; interns have no unique state.
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    for (int i = 0; i < 3; ++i) {
        if (formNames[i] == formName) { // if the form name passed as parameter exists (shrubbery creation, robotomy request, or presidential pardon)
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);  // Call the matching function (target is passed as parameter)
        }
    }
    std::cout << "Error: Form " << formName << " not found!" << std::endl;
    return NULL;
}
/*
makeForm takes two strings:
1. name of a form 2. target of the form.

returns a pointer to a Form object (whose name is the one passed as parameter)
whose target will be initialized to the second parameter.

prints something like: Intern creates <form>
If the form name passed as parameter doesn’t exist, print an explicit error message.
*/

AForm* Intern::createShrubberyCreation(const std::string &target) {
    return new ShrubberyCreationForm(target); // returns a pointer to a new ShrubberyCreationForm instance
}

AForm* Intern::createRobotomyRequest(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardon(const std::string &target) {
    return new PresidentialPardonForm(target);
}
