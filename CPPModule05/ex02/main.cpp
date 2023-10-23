/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:56:29 by dkham             #+#    #+#             */
/*   Updated: 2023/10/23 20:26:57 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for rand()

    Bureaucrat highRanking("High Ranker", 1);
    Bureaucrat lowRanking("Low Ranker", 150);

    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("human");
    PresidentialPardonForm pardon("criminal");

    std::cout << highRanking << std::endl;
    std::cout << lowRanking << std::endl;

    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;

    // Trying to sign the forms
    try {
        lowRanking.signForm(shrubbery);
        highRanking.signForm(shrubbery);

        lowRanking.signForm(robotomy);
        highRanking.signForm(robotomy);

        lowRanking.signForm(pardon);
        highRanking.signForm(pardon);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Trying to execute the forms
    try {
        lowRanking.executeForm(shrubbery);
        highRanking.executeForm(shrubbery);

        lowRanking.executeForm(robotomy);
        highRanking.executeForm(robotomy);

        lowRanking.executeForm(pardon);
        highRanking.executeForm(pardon);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
