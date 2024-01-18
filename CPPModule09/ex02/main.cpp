/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:35:09 by dkham             #+#    #+#             */
/*   Updated: 2024/01/18 20:01:04 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


// 최종 출력방식 점검
// jacobsthal 수열 값을 bk (pending 벡터) 의 인덱스로 사용해 이진탐색으로 main 벡터에 삽입
// 이때 각 pair를 기억하고 있어야 함 (예. a2는 b2와 연결). 고로 초기 상태의 pair를 그대로 두고, 정렬에 사용하는 pair를 따로 두어야 함.

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
