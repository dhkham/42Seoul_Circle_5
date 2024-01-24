/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:48:58 by dkham             #+#    #+#             */
/*   Updated: 2024/01/24 20:28:44 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>

class RPN {
public:
    RPN(); // Default constructor
    RPN(const std::string& expression); // Parameterized constructor
    RPN(const RPN& other); // Copy constructor
    RPN& operator=(const RPN& other); // Copy assignment operator
    ~RPN(); // Destructor
    int evaluate(const std::string& expression);

private:
    bool isOperator(const std::string& token);
    bool isNumber(const std::string& token);
    int performOperation(int a, int b, const std::string& op);
};

#endif
