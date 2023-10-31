/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:14:47 by dkham             #+#    #+#             */
/*   Updated: 2023/10/31 20:50:16 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

// sh tester.sh
int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./convert <scalar_value>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}

/*
int main(){
    // make a float value 2147483648.f
    float f = 214.7134f;
    //print
    std::cout << f << std::endl;
    // 214.713 출력
}

./convert 2147483648.f
char: impossible
int: impossible
float: 2.14748e+09f
double: 2.14748e+09

./convert 2147483648
char: impossible
int: impossible
float: 2.14748e+09f
double: 2.14748e+09

./convert -inff
char: impossible
int: impossible
float: -inff
double: -inf

./convert -inf                                                                            
char: impossible
int: impossible
float: -inff
double: -inf

*/