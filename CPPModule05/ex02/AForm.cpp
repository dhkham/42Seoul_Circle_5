/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:19:27 by dkham             #+#    #+#             */
/*   Updated: 2023/10/26 17:40:38 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Default constructor
AForm::AForm() 
: name("default"), gradeToSign(1), gradeToExecute(1) // providing default values
{
    std::cout << "Form default constructor called" << std::endl;
}

// Constructor with target
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

// Copy assignment operator
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        // Avoid self-assignment and directly copy each field from other
        signedStatus = other.signedStatus;
    }
    return *this;
}

// Copy constructor
AForm::AForm(const AForm& other)
    : name(other.name), signedStatus(other.signedStatus),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

// Destructor
AForm::~AForm() {}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::isSigned() const {
    return signedStatus;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    signedStatus = true;
}

void AForm::verifyExecution(const Bureaucrat& executor) const {
    if (!signedStatus) { // check if the form is signed
        throw AForm::NotSignedException();
    } else if (executor.getGrade() > gradeToExecute) { // check if the executor's grade is high enough
        throw AForm::GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low.";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Form is not signed.";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << form.getName() << ", form " << (form.isSigned() ? "is signed." : "is not signed.") 
       << " Required grade to sign: " << form.getGradeToSign()
       << ", required grade to execute: " << form.getGradeToExecute();
    return os;
}

// execute method is now pure virtual, so we can't instantiate an AForm object