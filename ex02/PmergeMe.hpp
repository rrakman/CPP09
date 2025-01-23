#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <sstream>

class PmergeMe
{
    private:
        std::vector<int> _v1;
        std::vector<int> _sorted_vec;
        std::deque<int> _sorted_deque;
        double time_vec;
        double time_deque;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &pmergeMe);
        PmergeMe &operator=(const PmergeMe &pmergeMe);
        ~PmergeMe();
        void store_input(int ac, char **av);
        void sort_both();
        void print_stats();
        template <typename T> 
        void Ford_Johnson(T &container);
};