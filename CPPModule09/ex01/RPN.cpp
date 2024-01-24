/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:53:22 by dkham             #+#    #+#             */
/*   Updated: 2024/01/24 20:42:47 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <stdexcept>

// Default constructor
RPN::RPN() {}

// Parameterized constructor
RPN::RPN(const std::string& expression) {
    try {
        int result = evaluate(expression);
        std::cout << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

// Copy constructor
RPN::RPN(const RPN& other) {
    *this = other;
}

// Copy assignment operator
RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        // Copy the data members from the other object
    }
    return *this;
}

// Destructor
RPN::~RPN() {}

// Function to check if a given string is an arithmetic operator
bool RPN::isOperator(const std::string& token) {
    // Return true if the token matches any of the four basic arithmetic operators
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// Function to check if a given string is a valid number (not allowing decimals)
bool RPN::isNumber(const std::string& token) {
    bool hasDecimal = false;  // Flag to detect decimal points
    // Iterate over each character in the string
    for (std::string::size_type i = 0; i < token.size(); ++i) {
        char c = token[i];  // Current character
        if (c == '.') {
            // If a decimal point is found and it's not the first one, return false
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!std::isdigit(c) && !(c == '-' && i == 0)) {
            // If the character is not a digit or a leading minus, return false
            return false;
        }
    }
    // Return true if the string is a number without a decimal point
    return !hasDecimal;
}

// Function to perform the given arithmetic operation on two integers
int RPN::performOperation(int a, int b, const std::string& op) {
    // Perform the operation based on the operator and return the result
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    // Handle division separately to check for division by zero
    if (op == "/") return b == 0 ? throw std::runtime_error("Division by zero") : a / b;
    // If the operator is not recognized, throw an error
    throw std::runtime_error("Invalid operator");
}

// Function to evaluate a given Reverse Polish Notation expression
int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);  // Stream to parse the input expression
    std::string token;  // Variable to hold each token in the expression
    std::stack<int> values;  // Stack to hold the intermediate values

    // Iterate over each token in the input expression
    while (iss >> token) {
        // Check if the token is an operator (+, -, *, /)
        if (isOperator(token)) {
            // Ensure there are at least two values on the stack for the operation
            if (values.size() < 2) {
                throw std::runtime_error("Invalid expression: insufficient operands");
            }
            // Pop the top two values from the stack
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            // Perform the operation and push the result back onto the stack
            values.push(performOperation(a, b, token));
        } else {
            // If the token is not an operator, it must be a number
            if (!isNumber(token)) {
                // If the token is not a valid number, throw an error
                throw std::runtime_error("Invalid expression: invalid input '" + token + "'");
            }
            // Convert the token to an integer and push it onto the stack
            values.push(std::stoi(token));
        }
    }

    // After processing all tokens, check if there is exactly one value left on the stack
    if (values.size() != 1) throw std::runtime_error("Invalid expression");
    // Return the final value from the stack
    return values.top();
}
