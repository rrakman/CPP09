#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> data;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void read_input(const std::string filename);
};