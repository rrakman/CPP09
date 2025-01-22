#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include <sstream>
#include<algorithm>

class BitcoinExchange
{
    private:
        std::map<std::string, float> data;
    public:
        BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &src);
        BitcoinExchange(const BitcoinExchange &src);
        ~BitcoinExchange();
        void read_input(const std::string filename);
        float get_btc_price(std::string date);

};