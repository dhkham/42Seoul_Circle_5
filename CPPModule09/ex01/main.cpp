/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:48:36 by dkham             #+#    #+#             */
/*   Updated: 2024/01/24 20:29:27 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[]) {
    // Check if the input provided through command line arguments is valid
    if (argc != 2) {
        std::cout << "Usage: ./RPN <expression>\n";
        return 1;
    }
    RPN calculator;
    try {
        // Evaluate the expression and print the result
        int result = calculator.evaluate(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }    

    return 0;
}
