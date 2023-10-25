/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:55:13 by dkham             #+#    #+#             */
/*   Updated: 2023/10/25 19:45:19 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
public:
    /*
    exception class:
    nested inside the Bureaucrat class, so that it is only visible to Bureaucrat
    */
    class GradeTooHighException : public std::exception { 
        const char* what() const throw(); // const after what() means that the function doesn't modify the object. throw() means that the function doesn't throw any exceptions.
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
