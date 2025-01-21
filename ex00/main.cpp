#include"BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        BitcoinExchange btc;
        btc.read_input(av[1]);
    }
    else
        std::cerr << "Error: argurments are not valid!"<< std::endl;
}