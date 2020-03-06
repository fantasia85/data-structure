#include <iostream>
#include "LLQueue.h"

int main()
{
    LLQueue<int> L1;
    std::cout << L1.QueueEmpty() << " " << L1.QueueLength() << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
        L1.EnQueue(i);
    std::cout << L1.QueueEmpty() << " " << L1.QueueLength() << std::endl;
    int e;
    for (int i = 0; i < 11; i++)
    {
        if (L1.GetHead(e))
        {
            L1.DeQueue(e);
            std::cout << e << " ";
        }
        else
            std::cout << "false";
    }
    std::cout << std::endl;
    std::cout << L1.QueueEmpty() << " " << L1.QueueLength() << std::endl;
    std::cout << std::endl;

    L1.ClearQueue();
    std::cout << L1.QueueEmpty() << " " << L1.QueueLength() << std::endl;
    std::cout << std::endl;

    //char型
    LLQueue<char> Lc;
    std::cout << Lc.QueueEmpty() << " " << Lc.QueueLength() << std::endl;
    std::cout << std::endl;

    for (char i = 'a'; i <= 'z'; i++)
        Lc.EnQueue(i);
    std::cout << Lc.QueueEmpty() << " " << Lc.QueueLength() << std::endl;
    char c;
    for (int i = 0; i < 27; i++)
    {
        if (Lc.GetHead(c))
        {
            Lc.DeQueue(c);
            std::cout << c << " ";
        }
        else
            std::cout << "false";
    }
    std::cout << std::endl;
    std::cout << Lc.QueueEmpty() << " " << Lc.QueueLength() << std::endl;
    std::cout << std::endl;

    Lc.ClearQueue();
    std::cout << Lc.QueueEmpty() << " " << Lc.QueueLength() << std::endl;
    std::cout << std::endl;

    system("pause");
    return 0;
}