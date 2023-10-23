/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:19:27 by dkham             #+#    #+#             */
/*   Updated: 2023/10/23 21:47:59 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() 
: name("default"), gradeToSign(1), gradeToExecute(1) // providing default values
{
    std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

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
    if (!signedStatus) {
        throw AForm::NotSignedException();
    } else if (executor.getGrade() > gradeToExecute) {
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
    os << "Form " << form.getName() << " (s.grade " << form.getGradeToSign() << ", ex.grade " << form.getGradeToExecute() << "), " << (form.isSigned() ? "signed" : "unsigned");
    return os;
}
