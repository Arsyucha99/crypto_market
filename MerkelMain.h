#pragma once

#include <vector>
#include "OrderBookEntry.h"

class MerkelMain {
    public:
        MerkelMain();

        void init();   /** Call this to start the simulation */

    private:                        // functions
        void load_order_book();
        void print_menu();
        void print_invalid();
        void print_help();
        void print_market_stats();
        void enter_offer();
        void enter_bid();
        void print_wallet();
        void goto_next_timeframe();
        unsigned short get_user_option();
        void process_option(unsigned short);

                                    // variables
        std::vector<OrderBookEntry> orders;
};