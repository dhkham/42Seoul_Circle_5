/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:17:29 by dkham             #+#    #+#             */
/*   Updated: 2023/10/26 19:16:54 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("default", 1, 1), target("default") {}

// Constructor with target
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), target(target) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}
    
// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    AForm::operator=(other); // Assign base part
    if (this != &other) {
        target = other.target; // Copy the target
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    verifyExecution(executor);
    
    std::string path = target + "_shrubbery";
    std::ofstream ofs(path.c_str()); // Create a file with the target name
    if (ofs) { // If the file was created successfully, write to it
        ofs << "       *       " << std::endl;
        ofs << "      ***      " << std::endl;
        ofs << "     *****     " << std::endl;
        ofs << "    *******    " << std::endl;
        ofs << "   *********   " << std::endl;
        ofs << "  ***********  " << std::endl;
        ofs << " ************* " << std::endl;
        ofs << "       |       " << std::endl; // This is the trunk of the tree
        ofs << "       |       " << std::endl;
        ofs.close();
    } else {
        throw std::runtime_error("Error: Unable to write to file");
    }
}
