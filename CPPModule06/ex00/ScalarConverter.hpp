/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:13:56 by dkham             #+#    #+#             */
/*   Updated: 2023/10/31 19:13:46 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <sstream> // Needed for std::istringstream

class ScalarConverter {
public:
    static void convert(const std::string &literal);
private:
    ScalarConverter();                                       // Default constructor
    ScalarConverter(const ScalarConverter &);                // Copy constructor
    ScalarConverter &operator=(const ScalarConverter &);     // Copy assignment operator
    ~ScalarConverter();                                      // Destructor

    static char doubleToChar(double value);
    static int doubleToInt(double value);
    static float doubleToFloat(double value);
    static double stringToDouble(const std::string& s);
};

#endif
