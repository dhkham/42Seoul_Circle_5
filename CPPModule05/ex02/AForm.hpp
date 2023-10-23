/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:39:45 by dkham             #+#    #+#             */
/*   Updated: 2023/10/23 21:47:03 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat; // Forward declaration

class AForm {
public:
    class GradeTooHighException : public std::exception {
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        virtual const char* what() const throw();
    };

    class NotSignedException : public std::exception {
        virtual const char* what() const throw();
    };

    AForm(); //default constructor
    AForm(const std::string& name, int gradeToSign, int gradeToExecute); // Constructor
    AForm(const AForm& other); // Copy constructor
    AForm& operator=(const AForm& other); // copy assignment operator
    virtual ~AForm(); // Destructor

    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(Bureaucrat const& executor) const = 0; // Making the class abstract with a pure virtual function

protected:
    void verifyExecution(const Bureaucrat& executor) const;

private:
    const std::string name;
    bool signedStatus;
    const int gradeToSign;
    const int gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
