#pragma once

#include <string>

enum class OrderBookType{bid, ask};

class OrderBookEntry {
    public: 
        OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _orderType);

        double price, amount;
        std::string timestamp, product;
        OrderBookType orderType;
};