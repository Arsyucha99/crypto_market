#include "CSVReader.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader() {}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFileName) {
    std::vector<OrderBookEntry> entries;
    std::string line;
    std::ifstream csvFile{csvFileName};
    if (csvFile.is_open()) {
        while (std::getline(csvFile, line)) {
            try {
                OrderBookEntry temp = str_to_OBE(tokenise(line, ','));
                entries.push_back(temp);
            } catch (const std::exception& e) {
                std::cout << "CSVReader::csvRead bad data" << std::endl;
            }
        }
    }
    std::cout << "CSVReader::csvRead reading " << entries.size() << " entries" << std::endl;
    return entries;
}

std::vector<std::string> CSVReader::tokenise (const std::string csvLine, const char separator) {
    std::vector<std::string> tokens;

    int end, start = csvLine.find_first_not_of(separator, 0);

    do {
        end = csvLine.find_first_of(separator, start);
        std::string token;

        if (start == csvLine.length() || start == end) break;

        if (end >= 0) token = csvLine.substr(start, end - start);

        else token = csvLine.substr(start, csvLine.length() - start);

        tokens.push_back(token);

        start = end + 1;
        
    } while (end != std::string::npos);
    
    return tokens;
}

OrderBookEntry CSVReader::str_to_OBE (std::vector<std::string> tokens) {
    double price, amount;
    if (tokens.size() != 5) {
        std::cout << "Bad line " << std::endl;
        throw std::exception{};
    }
    try {
        double price = stod(tokens[3]), amount = stod(tokens[4]);
        std::cout << "Price: " << price << ", amount: " << amount << std::endl;
    } catch(std::exception& e) {
        std::cout << "Bad float! " << tokens[3];
        std::cout << "Bad float! " << tokens[4];
        throw;
    }
    OrderBookEntry obe{price, amount, tokens[0], tokens[1], OrderBookEntry::str_to_OrderBooktype(tokens[2])};
    return obe;
}