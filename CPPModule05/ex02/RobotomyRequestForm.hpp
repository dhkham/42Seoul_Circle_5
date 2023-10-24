/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:15:49 by dkham             #+#    #+#             */
/*   Updated: 2023/10/24 18:56:29 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(); // Default constructor
    RobotomyRequestForm(const std::string& target); // Custom constructor for setting target
    RobotomyRequestForm(const RobotomyRequestForm& other); // Copy constructor
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other); // Copy assignment operator
    virtual ~RobotomyRequestForm(); // Destructor

    virtual void execute(Bureaucrat const& executor) const;

private:
    std::string target;
};

#endif
