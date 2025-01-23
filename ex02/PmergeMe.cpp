#include"PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe & PmergeMe::operator=(const PmergeMe &src) {
    if(this == &src)
        return *this;
    _v1 = src._v1;
    return *this;
}
PmergeMe::PmergeMe(const PmergeMe &pmergeMe) {
    *this = pmergeMe;
}
PmergeMe::~PmergeMe() {}


void PmergeMe::store_input(int ac, char **av)
{
    std::string args;
    std::stringstream ss;
    int i = 1;

    while(i < ac)
    {
        ss << av[i];
        while(ss >> args)
        {
            for (size_t i = 0; i < args.length(); i++)
            {
                if(args.at(i) == '-')
                {
                    std::cerr << "Error: negative number" << std::endl;
                    exit(1);
                }
                else if (args.at(i) == '+' && std::isdigit(args.at(i + 1)))
                {
                    continue;
                }
                else if (!std::isdigit(args.at(i)))
                {
                    std::cerr << "Error: not a number" << std::endl;
                    exit(1);
                }
            }
            _v1.push_back(std::atoi(args.c_str()));
        }
        ss.clear();
        i++;
    }
}

template <typename T>
void bi_Insertion(int n, T &list)
{
    typename T::iterator low, mid, high;

    low = list.begin();
    high = list.end();

    while (low < high)
    {
        mid = low + (high - low) / 2;

        if (*mid < n)
            low = mid + 1;
        else
            high = mid;
    }

    list.insert(low, n);
}

template <typename T>
void sortAllPairs(T &list)
{
    int tmp;
    int s = list.size();
    if (s % 2 != 0)
        s--;
    for (int i = 0; i < s; i += 2)
    {
        if (list.at(i) > list.at(i + 1))
        {
            tmp = list.at(i);
            list.at(i) = list.at(i + 1);
            list.at(i + 1) = tmp;
        }
    }
}


template <typename T>
void PmergeMe::Ford_Johnson(T &list)
{
    T pend;
    sortAllPairs(list);
    if (list.size() % 2 != 0)
    {
        pend.push_back(list.back());
        list.pop_back();
    }
    for (int i = list.size() - 2; i > 0; i -= 2)
    {
        pend.push_back(*(list.begin() + i));
        list.erase(list.begin() + i);
    }
    if (list.size() > 2)
        Ford_Johnson(list);

    for (size_t i = 0; i < pend.size(); i++)
        bi_Insertion<T>(pend.at(i), list);
}


void PmergeMe::sort_both()
{
    std::clock_t start, end;
    _sorted_vec.reserve(_v1.size());
    for (size_t i = 0; i < _v1.size(); i++)
    {
        _sorted_vec.push_back(_v1.at(i));
        _sorted_deque.push_back(_v1.at(i));
    }
    start = std::clock();
    Ford_Johnson(_sorted_vec);
    end = std::clock();
    time_vec = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    start = std::clock();
    Ford_Johnson(_sorted_deque);
    end = std::clock();
    time_deque = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::print_stats()
{
    std::cout<< "Before: ";
    for (size_t i = 0; i < _v1.size(); i++)
        std::cout << _v1.at(i) << " ";
    std::cout << std::endl;


    std::cout << "After: ";
    for (size_t i = 0; i < _sorted_vec.size(); i++)
        std::cout << _sorted_vec.at(i) << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _v1.size() << " elements with std::vector: " << std::fixed << std::setprecision(6) << time_vec << "s" << std::endl;
    std::cout << "Time to process a range of " << _v1.size() << " elements with std::deque: " << std::fixed << std::setprecision(6) << time_deque << "s" << std::endl;
}