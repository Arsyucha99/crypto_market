#include <iostream>
#include <vector>
#include "MerkelMain.h"
#include "OrderBookEntry.h"

MerkelMain::MerkelMain() {}

void MerkelMain::init() {
    load_order_book();
    unsigned short input;
    while(true) {
        print_menu();
        input = get_user_option();
        process_option(input);
    }
}

void MerkelMain::load_order_book() {
    orders.push_back(OrderBookEntry{1000, 0.002, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid});
    orders.push_back(OrderBookEntry{2000, 0.04, "2020/04/21 16:55:39.492615", "BTC/USDT", OrderBookType::ask});
}

void MerkelMain::print_menu() {
    std::cout << "1: Print help" << std::endl <<
            "2: Print exchange stats" << std::endl <<
            "3: Make an offer" << std::endl <<
            "4: Make a bid" << std::endl <<
            "5: Print wallet" << std::endl <<
            "6: Continue" << std::endl <<
            "================" << std::endl <<
            "Type 1-6" << std::endl;
}

unsigned short MerkelMain::get_user_option() {
    unsigned short userOption;
    std::cin >> userOption;
    std::cout << "You've chosen: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::print_help() {
    std::cout << "Help: Your aim is to make money $$$. Analyse the market and make bids and offers." << std::endl;
}

void MerkelMain::print_market_stats() {
    std::cout << "Orderbook contains: " << orders.size() << " entries" << std::endl;
}

void MerkelMain::enter_offer() {
    std::cout << "Make an offer." << std::endl;
}

void MerkelMain::enter_bid() {
    std::cout << "Make a bid." << std::endl;
}

void MerkelMain::print_wallet() {
    std::cout << "Your wallet is empty." << std::endl;
}

void MerkelMain::goto_next_timeframe() {
    std::cout << "Going to next time frame." << std::endl;
}

void MerkelMain::print_invalid() {
    std::cout << "Invalid choice. Choose 1-6." << std::endl;
}

void MerkelMain::process_option(unsigned short userOption) {
    switch (userOption) {
        case 1:
        print_help();
        break;
        case 2:
        print_market_stats();
        break;
        case 3:
        enter_offer();
        break;
        case 4:
        enter_bid();
        break;
        case 5:
        print_wallet();
        break;
        case 6:
        goto_next_timeframe();
        break;
        default:
        print_invalid();
    }
}