//测试程序：线性表

#include "sqlist_1.h"
#include <iostream>

int main()
{
    sqList<int> sq_1(10);
    std::cout << sq_1.ListEmpty() << " "  << sq_1.ListLength() << " " << sq_1.L_Size() << std::endl;
    std::cout << std::endl;
    
    int q = 10, *p = &q;
    for (; q >= 0; q--)
    {
      if (sq_1.ListInsert(0, p))
        std::cout << "insert: " << *p << std::endl;
      std::cout << sq_1.ListEmpty() << " " << sq_1.ListLength() << " " << sq_1.L_Size() << std::endl;
    }
    std::cout << std::endl;

    for (int i = 0; i < sq_1.ListLength(); i++)
      if (sq_1.GetElem(i, p))
        std::cout << *p << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    
    for (int i = 11; i >= 0; i--)
    {
        std::cout << i << " located in " << sq_1.LocateElem(&i) << std::endl;
    }
    std::cout << std::endl;
    
    int x = 5, *px = &x;
    if (sq_1.PriorElem(px, px))
      std::cout << "Priorelem: " << *px << std::endl;
    if (sq_1.NextElem(px, px))
      std::cout << "Nextelem: " << *px << std::endl;
    std::cout << std::endl;

    sq_1.ListDelete(5, px);
    std::cout << "Delete: " << *px << std::endl;
    for (int i = 0; i < sq_1.ListLength(); i++)
        if (sq_1.GetElem(i, p))
            std::cout << *p << " ";
    std::cout << std::endl;
    std::cout << sq_1.ListEmpty() << " " << sq_1.ListLength() << " " << sq_1.L_Size() << std::endl;
    std::cout << std::endl;

    sqList<int> sq_2(10);
    int q1 = 0, *p1 = &q1;
    for (; q1 <= 10; q1++)
    {
      if (sq_2.ListInsert(0, p1))
        ;
    }
    for (int i = 0; i < sq_2.ListLength(); i++)
      if (sq_2.GetElem(i, p1))
        std::cout << *p1 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    sq_1.merge_sq(sq_2);
    std::cout << sq_1.ListEmpty() << " " << sq_1.ListLength() << " " << sq_1.L_Size() << std::endl;
    for (int i = 0; i < sq_1.ListLength(); i++)
      if (sq_1.GetElem(i, p1))
        std::cout << *p1 << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    
    sq_1.ClearList();
    std::cout << sq_1.ListEmpty() << " " << sq_1.ListLength() << " " << sq_1.L_Size() << std::endl;
    
    system ("pause");
    return 0;
}