/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:14:47 by dkham             #+#    #+#             */
/*   Updated: 2023/11/17 21:13:37 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

// remove removethis.sh
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
//     float f = 2143333;
//     std::cout << f << std::endl;
// }
