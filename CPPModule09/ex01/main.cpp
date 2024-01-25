/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:48:36 by dkham             #+#    #+#             */
/*   Updated: 2024/01/25 17:17:20 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// 10 넘는 수 에러

int main(int argc, char* argv[]) {
    // Check if the input provided through command line arguments is valid
    if (argc != 2) {
        std::cout << "Usage: ./RPN <expression>\n";
        return 1;
    }
    
    // check if the 
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
