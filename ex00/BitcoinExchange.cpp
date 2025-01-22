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

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if(this == &src)
        return *this;
    data = src.data;
    return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}



BitcoinExchange::~BitcoinExchange() {}

static bool valid_Date(std::string date)
{
    if (date.size() != 10)
    {
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
            return false;
        }
    }
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    if (year < "2009" || year > "2023")
    {
        return false;
    }
    if (month < "01" || month > "12")
    {
        return false;
    }
    if (day < "01" || day > "31")
    {
        return false;
    }
    return true;
}

static float covert_to_float(std::string str)
{
    std::stringstream ss(str);
    float f = 0;
    ss >> f;
    return f;
}

static std::string trim_the_spaces(std::string str)
{
    size_t start = str.find_first_not_of(" ");
    size_t end = str.find_last_not_of(" ");
    return str.substr(start, end - start + 1);
}

static bool valid_number(const std::string& number_str) {
    if (number_str.empty())
        return false;
    size_t dot_count = std::count(number_str.begin(), number_str.end(), '.');
    if (dot_count > 1 || number_str.back() == '.')
        return false;
    std::string temp_str = number_str;
    if (temp_str.front() == '-')
        temp_str.front() = '0';
    std::string valid_chars = "0123456789.";
    if (temp_str.find_first_not_of(valid_chars) != std::string::npos)
        return false;
    return true;
}

float BitcoinExchange::get_btc_price(std::string date)
{
    std::map<std::string, float>::iterator it = data.begin();
    for (; it != data.end(); ++it)
    {
        if (it->first == date)
        {
            return it->second;
        }
        if(it->first > date)
        {
            return std::prev(it)->second;
        }
    }
    return -1;
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
            std::cerr << "Error: bad input (pipe needed) => " << line << std::endl;
            continue;
        }
        line = trim_the_spaces(line);        
        key = trim_the_spaces(line.substr(0, line.find("|")));
        value = trim_the_spaces(line.substr(line.find("|") + 1));
        if(!valid_Date(key))
        {
            std::cerr << "Error: bad input (invalid date) => " << key << std::endl;
            continue;
        }
        float value2 = covert_to_float(value);
        if(!valid_number(value) || value2 < 0 || value2 > 1000)
        {
            std::cerr << "Error: bad input (value) => " << value << std::endl;
            continue;
        }

        float btc_price = get_btc_price(key);
        if(btc_price == -1)
        {
            std::cerr << "Error: no data for date => " << key << std::endl;
            continue;
        }
        else
            std::cout << key << " => " << value << " => " << btc_price * value2 << std::endl;
    }
}
