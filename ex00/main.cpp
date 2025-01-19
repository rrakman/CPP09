#include"BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
        BitcoinExchange btc(av[1] , "./data.csv");
    else
        std::cerr << "Error: argurments are not valid!"<< std::endl;
}