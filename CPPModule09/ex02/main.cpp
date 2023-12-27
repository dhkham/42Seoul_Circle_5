/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:35:09 by dkham             #+#    #+#             */
/*   Updated: 2023/12/27 19:35:10 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	PmergeMe pmergeMe;

	try
	{
		pmergeMe.IsValidInput(argc, argv);
		pmergeMe.SortUsingContainer();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (1);
}
