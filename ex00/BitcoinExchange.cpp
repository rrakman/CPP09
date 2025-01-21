#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::string key;
    std::string value;
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: cannot open file data.csv" << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        key = line.substr(0, line.find(","));
        value = line.substr(line.find(",") + 1);
        std::stringstream ss(value);
        float f = 0;
        ss >> f;
        data[key] = f;
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::read_input(const std::string &filename)
{
    std::ifstream input_f(filename);
    if (!input_f.is_open())
    {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return;
    }
    
}
