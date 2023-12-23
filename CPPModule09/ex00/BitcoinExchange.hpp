/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:09:17 by dkham             #+#    #+#             */
/*   Updated: 2023/12/23 17:48:24 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange();
    void loadExchangeRatesFromCsv(const std::string& filename);
    void processInputFile(const std::string& filename);

private:
    std::map<std::string, double> exchangeRates; // Mapping dates to exchange rates
    void calculateAndPrintValue(const std::string& date, double value);
    std::string findClosestDate(const std::string& date);
    bool isValidDate(const std::string& date); // Added: Function to validate the date format and existence
};

#endif
