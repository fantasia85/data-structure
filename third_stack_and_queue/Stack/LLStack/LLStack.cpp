#include "LLStack.h"
#include <iostream>

int main()
{
    LLStack<int> L1;
    std::cout << L1.StackEmpty() << " " << L1.StackLength() << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
        L1.Push(i);
    std::cout << L1.StackEmpty() << " " << L1.StackLength() << std::endl;
    int e;
    for (int i = 0; i < 11; i++)
    {
        if (L1.GetTop(e))
        {
            L1.Pop(e);
            std::cout << e << " ";
        }
        else
            std::cout << "false";
    }
    std::cout << std::endl;
    std::cout << L1.StackEmpty() << " " << L1.StackLength() << std::endl;
    std::cout << std::endl;

    L1.ClearStack();
    std::cout << L1.StackEmpty() << " " << L1.StackLength() << std::endl;
    std::cout << std::endl;

    //char型
    LLStack<char> Lc;
    std::cout << L1.StackEmpty() << " " << L1.StackLength() << std::endl;
    std::cout << std::endl;

    for (char i = 'a'; i <= 'z'; i++)
        Lc.Push(i);
    std::cout << Lc.StackEmpty() << " " << Lc.StackLength() << std::endl;
    char c;
    for (int i = 0; i < 27; i++)
    {
        if (Lc.GetTop(c))
        {
            Lc.Pop(c);
            std::cout << c << " ";
        }
        else
            std::cout << "false";
    }
    std::cout << std::endl;
    std::cout << Lc.StackEmpty() << " " << Lc.StackLength() << std::endl;
    std::cout << std::endl;

    Lc.ClearStack();
    std::cout << Lc.StackEmpty() << " " << Lc.StackLength() << std::endl;
    std::cout << std::endl;

    system("pause");
    return 0;
}