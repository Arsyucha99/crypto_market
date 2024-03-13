#include <iostream>
#include "MerkelMain.h"

MerkelMain::MerkelMain() {
}

void MerkelMain::init() {
    unsigned short input;
    while(true) {
        print_menu();
        input = get_user_option();
        process_option(input);
    }
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
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::print_help() {
    std::cout << "Help: Your aim is to make money $$$. Analyse the market and make bids and offers." << std::endl;
}

void MerkelMain::print_market() {
    std::cout << "Market looks good." << std::endl;
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
        print_market();
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