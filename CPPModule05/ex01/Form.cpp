/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:39:52 by dkham             #+#    #+#             */
/*   Updated: 2023/10/25 20:32:20 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() 
: name("default"), gradeToSign(1), gradeToExecute(1) // providing default values
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& other)
    : name(other.name), signedStatus(other.signedStatus),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other) {
    signedStatus = other.signedStatus; // We can't assign 'name', 'gradeToSign', and 'gradeToExecute' since they're constant
    return *this;
}

Form::~Form() {}

// Getters
const std::string& Form::getName() const {
    return name;
}

bool Form::isSigned() const {
    return signedStatus;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}

// Member functions
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) { // if bureaucrat's grade is low, throw an exception
        throw GradeTooLowException();
    }
    signedStatus = true; // change the form status to signed if the bureaucrat’s grade is high enough
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade too low!";
}

// Overload << operator: prints all the form's attributes
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName() << ", form " << (form.isSigned() ? "is signed." : "is not signed.") 
       << " Required grade to sign: " << form.getGradeToSign()
       << ", required grade to execute: " << form.getGradeToExecute() << std::endl;
    return os;
}
