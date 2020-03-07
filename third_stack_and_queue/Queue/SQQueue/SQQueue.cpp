#include "SQQueue.h"
#include <iostream>

int main()
{
    SQQueue<int> S1;
    std::cout << S1.QueueEmpty() << " " << S1.QueueLength() << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
        S1.EnQueue(i);
    std::cout << S1.QueueEmpty() << " " << S1.QueueLength() << std::endl;
    int e;
    for (int i = 0; i < 11; i++)
    {
        if (S1.GetHead(e))
        {
            S1.DeQueue(e);
            std::cout << e << " ";
        }
        else
            std::cout << "false";
    }
    std::cout << std::endl;
    std::cout << S1.QueueEmpty() << " " << S1.QueueLength() << std::endl;
    std::cout << std::endl;

    S1.ClearQueue();
    std::cout << S1.QueueEmpty() << " " << S1.QueueLength() << std::endl;
    std::cout << std::endl;

    //char型
    SQQueue<char> Sc;
    std::cout << Sc.QueueEmpty() << " " << Sc.QueueLength() << std::endl;
    std::cout << std::endl;

    for (char i = 'a'; i <= 'z'; i++)
        Sc.EnQueue(i);
    std::cout << Sc.QueueEmpty() << " " << Sc.QueueLength() << std::endl;
    char c;
    for (int i = 0; i < 27; i++)
    {
        if (Sc.GetHead(c))
        {
            Sc.DeQueue(c);
            std::cout << c << " ";
        }
        else
            std::cout << "false";
    }
    std::cout << std::endl;
    std::cout << Sc.QueueEmpty() << " " << Sc.QueueLength() << std::endl;
    std::cout << std::endl;

    Sc.ClearQueue();
    std::cout << Sc.QueueEmpty() << " " << Sc.QueueLength() << std::endl;
    std::cout << std::endl;

    system("pause");
    return 0;
}