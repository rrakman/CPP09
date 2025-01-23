#include"PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac >= 2)
    {
        PmergeMe pmergeMe;
        pmergeMe.store_input(ac, av);
        pmergeMe.sort_both();
        pmergeMe.print_stats();
    }
    return 0;
}