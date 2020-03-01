#include "SQStack.h"
#include <iostream>

int main ()
{
    SQStack<int> S1(1);
    SQStack<int> S2;
    std::cout << S1.StackEmpty() << " " << S1.StackLength() << std::endl;
    std::cout << S2.StackEmpty() << " " << S2.StackLength() << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
        S1.Push(i);
    std::cout << S1.StackEmpty() << " " << S1.StackLength() << std::endl;
    int e;
    for (int i = 0; i < 11; i++)
    {
        if (S1.GetTop(e))
        {
            S1.Pop(e);
            std::cout << e << " ";
        }
        else 
            std::cout << "false";
    }
    std::cout << std::endl;
    std::cout << S1.StackEmpty() << " " << S1.StackLength() << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
        S2.Push(i);
    std::cout << S2.StackEmpty() << " " << S2.StackLength() << std::endl;
    for (int i = 0; i < 11; i++)
    {
        if (S2.GetTop(e))
        {
            S2.Pop(e);
            std::cout << e << " ";
        }
        else
            std::cout << "false";
    }
    std::cout << std::endl;
    std::cout << S2.StackEmpty() << " " << S2.StackLength() << std::endl;
    std::cout << std::endl;

    //char型
    SQStack<char> Sc(1);
    std::cout << S1.StackEmpty() << " " << S1.StackLength() << std::endl;
    std::cout << std::endl;

    for (char i = 'a'; i <= 'z'; i++)
        Sc.Push(i);
    std::cout << Sc.StackEmpty() << " " << Sc.StackLength() << std::endl;
    char c;
    for (int i = 0; i < 27; i++)
    {
        if (Sc.GetTop(c))
        {
            Sc.Pop(c);
            std::cout << c << " ";
        }
        else
            std::cout << "false";
    }
    std::cout << std::endl;
    std::cout << Sc.StackEmpty() << " " << Sc.StackLength() << std::endl;
    std::cout << std::endl;

    system ("pause");
    return 0;
}