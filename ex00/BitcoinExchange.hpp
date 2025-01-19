#pragma once
#include<iostream>
#include<map>
#include<fstream>

class BitcoinExchange
{
    private:
        std::map<std::string, std::string> data;
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string input_file, const std::string btc_data_csv);
        ~BitcoinExchange();

};