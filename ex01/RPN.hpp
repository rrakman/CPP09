#pragma once
#include<iostream>
#include<stack>
#include<algorithm>
#include<sstream>

class RPN {
    private:
        std::stack<int> stack;
        std::string str;
    public:
        RPN();
        ~RPN();
        void store_and_calculate(const std::string &str);
};