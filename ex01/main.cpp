#include"RPN.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return 1;
    }
    RPN rpn;
    std::string arg(av[1]);
    rpn.store_and_calculate(arg);
    return 0;
}