/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:18:09 by dkham             #+#    #+#             */
/*   Updated: 2023/10/24 18:53:05 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() 
: AForm("default", 1, 1), target("default") {}

// Constructor with target
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon", 25, 5), target(target) {}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), target(other.target) {}

// Copy assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    AForm::operator=(other); // Assign base part
    if (this != &other) {
        target = other.target; // Copy the target
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    verifyExecution(executor);
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
