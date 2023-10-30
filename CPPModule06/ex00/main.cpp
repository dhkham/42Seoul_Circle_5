/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:14:47 by dkham             #+#    #+#             */
/*   Updated: 2023/10/30 19:49:40 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./convert <scalar_value>" << std::endl;
        return 1;
    }
    
    ScalarConverter::convert(argv[1]);
    return 0;
}

// int main(){
//     // make a float value 2147483648.f
//     float f = 1.;
//     //print
//     std::cout << f << std::endl;
// }

/*

./convert 2147483648.f
char: impossible
int: impossible
float: 2.14748e+09f
double: 2.14748e+09

./convert 2147483648 (해결 필요)
char: impossible
int: impossible
float: impossible
double: impossible

-> 이 경우 들어온 값이 숫자인데 int float double 다 아니므로 모두 impossible처리

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