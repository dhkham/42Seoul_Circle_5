/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:09:00 by dkham             #+#    #+#             */
/*   Updated: 2023/12/23 17:49:04 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btcExchange;
    btcExchange.loadExchangeRatesFromCsv("data.csv"); // Assuming the CSV file is named 'data.csv'
    btcExchange.processInputFile(argv[1]);

    return 0;
}
