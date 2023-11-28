/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:49:29 by dkham             #+#    #+#             */
/*   Updated: 2023/11/28 20:36:08 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    // non const version
    int intArr[] = {1, 2, 3};
    char strArr[] = {'a', 'b', 'c'};
    size_t intArrLength = sizeof(intArr) / sizeof(intArr[0]);
    size_t strArrLength = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "<<< BEFORE >>>" << std::endl << std::endl;
    
    // apply printArray
    std::cout << "intArr:" << std::endl;
    iter(intArr, intArrLength, printArray);
    std::cout << std::endl;

    std::cout << "strArr:" << std::endl;
    iter(strArr, strArrLength, printArray);
    std::cout << std::endl;

    // apply incrementArray
    iter(intArr, intArrLength, incrementArray);
    iter(strArr, strArrLength, incrementArray);
    std::cout << std::endl;

    std::cout << "<<< AFTER >>>" << std::endl << std::endl;
    
    // apply printArray
    std::cout << "intArr:" << std::endl;
    iter(intArr, intArrLength, printArray);
    std::cout << std::endl;

    std::cout << "char_array:" << std::endl;
    iter(strArr, strArrLength, printArray);
    std::cout << std::endl;

    // const version
    std::cout << "*************************************************************" << std::endl << std::endl;
    const int const_intArr[] = {1, 2, 3};
    const char const_strArr[] = {'a', 'b', 'c'};
    size_t const_intArrLength = sizeof(const_intArr) / sizeof(const_intArr[0]);
    size_t const_strArrLength = sizeof(const_strArr) / sizeof(const_strArr[0]);
        
    // apply printArray
    std::cout << "const_intArr:" << std::endl;
    iter(const_intArr, const_intArrLength, printArray);
    std::cout << std::endl;
    
    std::cout << "const_strArr:" << std::endl;
    iter(const_strArr, const_strArrLength, printArray);
    std::cout << std::endl;

    return 0;
}
