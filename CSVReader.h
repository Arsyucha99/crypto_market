#pragma once

#include "OrderBookEntry.h"
#include <vector>
#include <string>

class CSVReader {
    public:
        CSVReader();

        static std::vector<OrderBookEntry> readCSV(std::string csvFileName);

    private:
        static std::vector<std::string> tokenise (const std::string csvLine, const char separator);
        static OrderBookEntry str_to_OBE (std::vector<std::string> strings);

};