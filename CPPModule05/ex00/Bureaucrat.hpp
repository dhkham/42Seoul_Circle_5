/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:55:13 by dkham             #+#    #+#             */
/*   Updated: 2023/10/23 21:37:48 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
    
    Bureaucrat();     //default constructor
    Bureaucrat(const std::string& name, int grade); // Constructor
    Bureaucrat(const Bureaucrat& other); // Copy constructor
    Bureaucrat& operator=(const Bureaucrat& other); // copy assignment operator
    virtual ~Bureaucrat(); // Destructor

    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

private:
    const std::string name;
    int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
