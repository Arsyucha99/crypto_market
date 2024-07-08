#include "CSVReader.h"

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

OrderBookEntry CSVReader::str_to_OBE (std::vector<std::string> strings) {
    OrderBookEntry obe{1, 1, "", "", OrderBookType::bid};
}