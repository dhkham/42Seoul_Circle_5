/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:09:00 by dkham             #+#    #+#             */
/*   Updated: 2024/01/25 18:59:36 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) { // Check if the number of arguments is correct (e.g., ./btc input.txt)
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btcExchange; // Create an instance of the BitcoinExchange class
    btcExchange.loadExchangeRatesFromCsv("data.csv"); // Assuming the CSV file is named 'data.csv'
    btcExchange.processInputFile(argv[1]); // Process the input file

    return 0;
}
