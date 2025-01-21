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

static bool valid_Date(std::string date)
{
    if (date.size() != 10)
    {
        // std::cout<<date<<std::endl;
        return false;
    }
    if (date[4] != '-' || date[7] != '-')
    {

        return false;
    }
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9'){
            std::cout << "here" << std::endl;
            return false;

        }
    }
    return true;
}

static std::string trim_the_spaces(std::string str)
{
    size_t start = str.find_first_not_of(" ");
    size_t end = str.find_last_not_of(" ");
    return str.substr(start, end - start + 1);
}



void BitcoinExchange::read_input(const std::string filename)
{
    std::ifstream input_f(filename);
    if (!input_f.is_open())
    {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return;
    }
    std::string line, key, value;
    getline(input_f, line);
    size_t start = line.find_first_not_of(" ");
    size_t end = line.find_last_not_of(" ");
    line = line.substr(start, end - start + 1);
    if (line != "date | value")
    {
        std::cerr << "Error: invalid file format" << std::endl;
        return;
    }
    while(getline(input_f, line))
    {
        size_t pipe = line.find("|");
        if(pipe == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        line = trim_the_spaces(line);        
        key = trim_the_spaces(line.substr(0, line.find("|")));
        value = trim_the_spaces(line.substr(line.find("|") + 1));

        if(!valid_Date(key))
        {
            std::cerr << "Error: bad input => " << key << std::endl;
            continue;
        }
        
    }
    
}
