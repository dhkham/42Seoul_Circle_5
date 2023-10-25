/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:56:29 by dkham             #+#    #+#             */
/*   Updated: 2023/10/25 19:07:22 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // Testing form creation with invalid grades
    try {
        Form invalidHigh("InvalidHigh", 0, 100);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Form invalidLow("InvalidLow", 151, 100);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Creating bureaucrats
    Bureaucrat highRank("High Rank", 1);
    Bureaucrat lowRank("Low Rank", 150);
    std::cout << highRank << std::endl;
    std::cout << lowRank << std::endl;

    // Creating a form
    Form f1("Form1", 50, 50); // name: Form1, grade to sign: 50, grade to execute: 50

    // Attempting to sign with lowRank (should fail)
    std::cout << f1 << std::endl;
    lowRank.signForm(f1);

    // Attempting to sign with highRank (should succeed)
    highRank.signForm(f1);
    std::cout << f1 << std::endl;

    // Creating a form that requires the highest rank to sign
    Form highForm("High Form", 1, 1);
    std::cout << highForm << std::endl;
    
    // Attempting to sign with highRank (should succeed)
    highRank.signForm(highForm);
    std::cout << highForm << std::endl;

    return 0;
}
