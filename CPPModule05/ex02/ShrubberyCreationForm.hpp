/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:15:26 by dkham             #+#    #+#             */
/*   Updated: 2023/10/24 18:58:44 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(); // Default constructor
    ShrubberyCreationForm(const std::string& target); // Custom constructor for setting target
    ShrubberyCreationForm(const ShrubberyCreationForm& other); // Copy constructor
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other); // Copy assignment operator
    virtual ~ShrubberyCreationForm(); // Destructor

    virtual void execute(Bureaucrat const& executor) const;

private:
    std::string target;
};

#endif
