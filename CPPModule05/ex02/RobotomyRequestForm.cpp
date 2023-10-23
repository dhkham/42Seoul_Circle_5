/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:17:56 by dkham             #+#    #+#             */
/*   Updated: 2023/10/23 20:17:57 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    verifyExecution(executor);

    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2) {
        std::cout << target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomy of " << target << " failed." << std::endl;
    }
}
