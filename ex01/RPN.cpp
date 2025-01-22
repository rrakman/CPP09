#include "RPN.hpp"


RPN::RPN()
{

}

RPN &RPN::operator=(const RPN &src)
{
    if(this == &src)
        return *this;
    stack = src.stack;
    input = src.input;
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
    for (size_t i = 0; i < input.size(); i= i + 2)
    {
        if(std::isdigit(input.at(i)))
            stack.push(toint(input.at(i)));
        else if (op.find(input.at(i)) != std::string::npos)
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: not enough nums" << std::endl;
                return;
            }
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            if (input.at(i) == '+')
                stack.push(a + b);
            else if (input.at(i) == '-')
                stack.push(b - a);
            else if (input.at(i) == '*')
                stack.push(a * b);
            else if (input.at(i) == '/')
            {
                if (a == 0)
                {
                    std::cerr << "Error: division by zero" << std::endl;
                    return;
                }
                stack.push(b / a);
            }
        }
        else
        {
            std::cerr << "Error: invalid character" << std::endl;
            return;
        }
    }
    if (stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << stack.top() << std::endl;
}
