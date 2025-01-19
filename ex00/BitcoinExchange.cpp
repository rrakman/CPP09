#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}


BitcoinExchange::BitcoinExchange(const std::string input_file, const std::string btc_data_csv);
{
    ifstream file(btc_data_csv);
    if (!file.is_open())
    {
        std::cerr << "Error: cannot open file " << btc_data_csv << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::string key = line.substr(0, line.find(","));
        std::string value = line.substr(line.find(",") + 1);
        data[key] = value;
    }

}
