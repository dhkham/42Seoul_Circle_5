/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:39:45 by dkham             #+#    #+#             */
/*   Updated: 2023/10/23 21:39:49 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat; // Forward declaration

class Form {
public:
    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw();
    };
    
    Form(); //default constructor
    Form(const std::string& name, int gradeToSign, int gradeToExecute); // Constructor
    Form(const Form& other); // Copy constructor
    Form& operator=(const Form& other); // copy assignment operator
    virtual ~Form(); // Destructor

    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);

private:
    const std::string name;
    bool signedStatus;
    const int gradeToSign;
    const int gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& form); // overload << operator

#endif
