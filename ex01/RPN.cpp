#include "RPN.hpp"


RPN::RPN()
{

}

RPN &RPN::operator=(const RPN &src)
{
    if(this == &src)
        return *this;
    stack = src.stack;
    str = src.str;
    return *this;
}

RPN::RPN(const RPN &src)
{
    *this = src;
}

RPN::~RPN()
{

}


static int toint(char c)
{
        return c - '0';
}


void RPN::store_and_calculate(const std::string &str)
{
    std::string op("+-*/");
    this->input = str;
    while (!stack.empty())
        stack.pop();
    for (int i = 0; i<= )
}
