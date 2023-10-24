/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:58:14 by dkham             #+#    #+#             */
/*   Updated: 2023/10/24 21:32:43 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Initialize static arrays
const std::string Intern::formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
const Intern::FormCreator Intern::formCreators[] = {&Intern::createShrubberyCreation, &Intern::createRobotomyRequest, &Intern::createPresidentialPardon};

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
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);  // Call the matching form creation function
        }
    }
    std::cout << "Error: Form " << formName << " not found!" << std::endl;
    return nullptr;
}

AForm* Intern::createShrubberyCreation(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequest(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardon(const std::string &target) {
    return new PresidentialPardonForm(target);
}
