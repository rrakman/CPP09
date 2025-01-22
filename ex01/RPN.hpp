#pragma once
#include<iostream>
#include<stack>
#include<algorithm>
#include<sstream>

class RPN {
    private:
        std::stack<int> stack;
        std::string input;
    public:
        RPN();
        ~RPN();
        RPN &operator=(const RPN &src);
        RPN(const RPN &src);
        void store_and_calculate(const std::string &str);
};