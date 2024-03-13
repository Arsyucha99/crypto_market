

class MerkelMain {
    public:
        MerkelMain();

        /** Call this to start the simulation */
        void init();

        void print_menu();

        void print_invalid();

        void print_help();

        void print_market();

        void enter_offer();

        void enter_bid();

        void print_wallet();

        void goto_next_timeframe();

        unsigned short get_user_option();

        void process_option(unsigned short);
};