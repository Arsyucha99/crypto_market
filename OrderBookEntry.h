#pragma once

#include <string>

enum class OrderBookType{bid, ask, uknown};

class OrderBookEntry {
    public: 
        OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _orderType);
        static OrderBookType str_to_OrderBooktype(std::string);

        double price, amount;
        std::string timestamp, product;
        OrderBookType orderType;
};