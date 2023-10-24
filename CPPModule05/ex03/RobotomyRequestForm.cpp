/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:17:56 by dkham             #+#    #+#             */
/*   Updated: 2023/10/24 18:57:35 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

// Default constructor
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("default", 1, 1), target("default") {}
    
// Constructor with target
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), target(target) {}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {}
    
// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    AForm::operator=(other); // Assign base part
    if (this != &other) {
        target = other.target; // Copy the target
    }
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    verifyExecution(executor);

    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2) { // rand() will return a random number between 0 and RAND_MAX
        std::cout << target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomy of " << target << " failed." << std::endl;
    }
}
