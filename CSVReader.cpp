#include "CSVReader.h"
#include <iostream>

CSVReader::CSVReader()
{

}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFileName) {
    std::vector<OrderBookEntry> entries;
    return entries;
}

std::vector<std::string> CSVReader::tokenise (const std::string csvLine, const char separator) {
    std::vector<std::string> tokens;
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