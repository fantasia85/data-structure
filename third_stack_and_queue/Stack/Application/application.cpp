#include "SQStack.h"
#include <iostream>
#include <string>

void conversion_to_8 (); //将一个10进制数转换为8进制

bool matching (); //括号匹配检验，当均匹配时，返回true，否则返回false

void LineEdit(); //行编辑程序

int main()
{
    //conversion_to_8();

    //bool res = matching();
    //std::cout << std::boolalpha << res << std::endl;

    LineEdit();

    system ("pause");
    return 0;
}

void conversion_to_8()
{
    SQStack<int> S1;
    int N;
    std::cout << "Input N:";
    std::cin >> N;
    while (N)
    {
        S1.Push(N % 8);
        N /= 8;
    }

    int n;
    while (!S1.StackEmpty())
    {
        S1.Pop(n);
        std::cout << n;
    }
    std::cout << std::endl;
}

bool matching ()
{
    SQStack<char> SC1;
    std::string s;
    std::cout << "Input string:";
    std::getline (std::cin, s);
    for (char c : s)
    {
        if (c == '[' || c == '{' || c == '(')
            SC1.Push(c);
        else if (c == ']' || c == '}' || c == ')')
        {
            char c1;
            if (!SC1.StackEmpty() && SC1.GetTop(c1))
            {
                switch (c1)
                {
                    case '[': if (c == ']') SC1.Pop(c); else return false; break;
                    case '{': if (c == '}') SC1.Pop(c); else return false; break;
                    case '(': if (c == ')') SC1.Pop(c); else return false; break;
                    default: return false;
                }
            }
            else 
                return false;
        }
        else
        {
            return false;
        }
    }
    if (SC1.StackEmpty())
        return true;
    else
        return false;
}

void LineEdit()
{
    SQStack<char> sl;
    std::string s;
    while (1)
    {
        std::cout << "Input string:";
        std::getline (std::cin, s);
        char temp;
        for (char c : s)
        {
            if (c == '#')
            {
                if (!sl.StackEmpty())
                {
                    sl.Pop(temp);
                }
            }
            else if (c == '@')
                sl.ClearStack();
            else
                sl.Push(c);
        }
        SQStack<char> s2;
        while (!sl.StackEmpty())
        {
            sl.Pop(temp);
            s2.Push(temp);
        }
        while (!s2.StackEmpty())
        {
            s2.Pop(temp);
            std::cout << temp;
        }
        std::cout << std::endl;
    }
}