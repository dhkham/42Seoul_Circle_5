/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:58:08 by dkham             #+#    #+#             */
/*   Updated: 2023/10/24 21:32:50 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
public:
    Intern(); // Default constructor
    Intern(const Intern &other); // Copy constructor
    Intern &operator=(const Intern &other); // Assignation operator
    ~Intern(); // Destructor

    AForm* makeForm(const std::string &formName, const std::string &target);

private:
    typedef AForm* (Intern::*FormCreator)(const std::string &target);
    static const std::string formNames[3];  // Array of form names
    static const FormCreator formCreators[3];  // Array of form creation functions

    AForm* createShrubberyCreation(const std::string &target);
    AForm* createRobotomyRequest(const std::string &target);
    AForm* createPresidentialPardon(const std::string &target);
};

#endif
