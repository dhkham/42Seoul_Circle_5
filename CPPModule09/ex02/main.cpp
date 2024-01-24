/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:35:09 by dkham             #+#    #+#             */
/*   Updated: 2024/01/24 20:06:31 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// merge sort 이해하기
// list 작동방식 이해하기

int main(int argc, char** argv)
{
    PmergeMe pmergeme;     // Create an instance of the PmergeMe class
    try
    {
        // Check if the input provided through command line arguments is valid
        pmergeme.checkValidInput(argc, argv);

        // If the input is valid, proceed to sort the sequence using the specified container
        pmergeme.runSort();
    }
    catch (std::exception& e)
    {
        // Catch and print any exceptions thrown during the validation or sorting process
        std::cout << e.what() << std::endl;
    }
    return (1);
}
