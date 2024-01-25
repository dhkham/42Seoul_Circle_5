#include "BitcoinExchange.hpp"

// Constructor for the BitcoinExchange class.
BitcoinExchange::BitcoinExchange() {}

// Parameterized constructor for the BitcoinExchange class.
BitcoinExchange::BitcoinExchange(const std::string& ratesFile, const std::string& inputFile) {
    loadExchangeRatesFromCsv(ratesFile); // Load the exchange rates from the CSV file.
    processInputFile(inputFile); // Process the input file.
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

// Copy assignment operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        // Copy the data members from the other object
        exchangeRates = other.exchangeRates;
    }
    return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

// Loads exchange rates from a CSV file into the exchangeRates map.
void BitcoinExchange::loadExchangeRatesFromCsv(const std::string& filename) {
    std::ifstream file(filename); // Open the file.
    std::string line, date;       // Variables for reading the file.
    double rate;

    // Check if the file is open, exit with an error message if not.
    if (!file.is_open()) {
        std::cout << "Error: could not open exchange rates file.\n";
        exit(1);
    }

    getline(file, line); // Skip the header line.

    // Read each line from the file.
    while (getline(file, line)) {
        std::istringstream iss(line);
        // Parse date and rate from the line. Skip the line if parsing fails.
        if (!getline(iss, date, ',') || !(iss >> rate)) { // extracts characters from iss and stores them in date until it encounters a comma. Then, it extracts the rate from iss and stores it in rate.
            std::cout << "Error: bad data in exchange rates file => " << line << std::endl;
            exit(1); // Terminate the program on parsing failure
        }

        // Validate date and value
        if (!isValidDate(date)) {
            std::cout << "Error: invalid date format (follow YYYY-MM-DD) => " << date << std::endl;
            exit(1); // Terminate the program on invalid date or negative rate
        }

        if (rate < 0) {
            std::cout << "Error: negative rate in exchange rates file => " << rate << std::endl;
            exit(1); // Terminate the program on negative rate
        }

        exchangeRates[date] = rate; // Store the rate in the map with the date as the key.
    }

    file.close(); // Close the file after reading.
}

// Finds the closest date in the exchangeRates map that is less than or equal to the given date.
std::string BitcoinExchange::findClosestDate(const std::string& date) {
    // Iterator to traverse the map.
    std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);

    // Adjust the iterator to find the closest lower date if the exact date is not found.
    if (it != exchangeRates.begin() && (it == exchangeRates.end() || it->first != date)) {
        --it;
    }
    return it->first; // Return the closest date.
}

// Calculates the Bitcoin value based on the exchange rate and prints it.
void BitcoinExchange::calculateAndPrintValue(const std::string& date, double value) {
    std::string closestDate = findClosestDate(date); // Find the closest date in the data.
    double exchangeRate = exchangeRates[closestDate]; // Retrieve the exchange rate for that date.

    // Handle the case where no exchange rate is available for the closest date.
    if (exchangeRate == 0 && date != closestDate) {
        std::cout << date << "=> " << value << " = " << "No exchange rate available for this date" << std::endl;
    } else {
        // Calculate and print the value based on the exchange rate.
        std::cout << date << "=> " << value << " = " << (value * exchangeRate) << std::endl;
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false; // Check the format (YYYY-MM-DD)
    }

    int year, month, day;
    std::istringstream dateStream(date);
    dateStream >> year;
    dateStream.ignore(); // Ignore the dash
    dateStream >> month;
    dateStream.ignore(); // Ignore the dash
    dateStream >> day;

    if (year < 0 || month < 1 || month > 12 || day < 1) {
        return false; // Basic range checks
    }

    // Days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for leap year
    if (month == 2 && (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))) { // leap year if divisible by 400 or divisible by 4 but not 100
        daysInMonth[1] = 29;
    }

    // Check the day is within the range for the month, return true if so.
    return day <= daysInMonth[month - 1];
}

// Processes each line in the input file to calculate and print the Bitcoin value.
void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename); // Open the input file.
    std::string line, date, valueStr;
    double value;

    // Check if the file is open, exit with an error message if not.
    if (!file.is_open()) {
        std::cout << "Error: could not open input file." << std::endl;
        exit(1);
    }

    // Read each line from the file.
    while (getline(file, line)) {
        std::istringstream iss(line);
        // Parse date and value from the line, display an error for bad input.
        if (!getline(iss, date, '|') || !(iss >> value)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Trim leading spaces from the date string.
        date.erase(0, date.find_first_not_of(" \t")); // finds the first character that is not a space or tab and erases everything before it
        // Trim trailing spaces from the date string.
        date.erase(date.find_last_not_of(" \t") + 1); // finds the last character that is not a space or tab and erases everything after it

        // Validate the date, ensuring it's in the correct format.
        if (!isValidDate(date)) {
            std::cout << "Error: invalid date format (follow YYYY-MM-DD) => " << date << std::endl;
            continue;
        }

        // Validate the value, ensuring it's positive and within the specified range.
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        // Calculate and print the Bitcoin value based on the exchange rate.
        calculateAndPrintValue(date, value);
    }

    file.close(); // Close the file after processing.
}
