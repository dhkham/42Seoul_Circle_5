/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:16:04 by dkham             #+#    #+#             */
/*   Updated: 2023/10/24 18:51:34 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(); // Default constructor
    PresidentialPardonForm(const std::string& target); // Custom constructor for setting target
    PresidentialPardonForm(const PresidentialPardonForm& other); // Copy constructor
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other); // Copy assignment operator
    virtual ~PresidentialPardonForm(); // Destructor

    virtual void execute(Bureaucrat const& executor) const;

private:
    std::string target;
};

#endif
