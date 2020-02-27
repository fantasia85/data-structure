#include "link_list_1.h"
#include <iostream>

int main ()
{
    //链表元素类型为int型
    link_list<int> list1;
    int e1, e2;
    std::cout << list1.ListEmpty() << " " << list1.ListLength() << " " << list1.L_size() << std::endl;
    std::cout << std::endl;

    if (list1.FirstIns(10))
    {
        std::cout << list1.ListEmpty() << " " << list1.ListLength() << " " << list1.L_size() << std::endl;
        for (int i = 1; i <= list1.ListLength(); i++)
            if (list1.GetElem(i, e1))
                std::cout << e1 << " ";
        std::cout << std::endl;
        std::cout << std::endl;
    }

    if (list1.AppendElem(5))
    {
        std::cout << list1.ListEmpty() << " " << list1.ListLength() << " " << list1.L_size() << std::endl;
        for (int i = 1; i <= list1.ListLength(); i++)
            if (list1.GetElem(i, e1))
                std::cout << e1 << " ";
        std::cout << std::endl;
        std::cout << std::endl;
    }

    if (list1.FirstDel(e2))
    {
        std::cout << list1.ListEmpty() << " " << list1.ListLength() << " " << list1.L_size() << std::endl;
        std::cout << e2 << std::endl;
        for (int i = 1; i <= list1.ListLength(); i++)
            if (list1.GetElem(i, e1))
                std::cout << e1 << " ";
        std::cout << std::endl; 
        std::cout << std::endl;
    }

    if (list1.RemoveElem(e2))
    {
        std::cout << list1.ListEmpty() << " " << list1.ListLength() << " " << list1.L_size() << std::endl;
        std::cout << e2 << std::endl;
        for (int i = 1; i <= list1.ListLength(); i++)
            if (list1.GetElem(i, e1))
                std::cout << e1 << " ";
        std::cout << std::endl;
        std::cout << std::endl;
    }

    list1.FirstIns(11);
    for (int i = 1; i <= 10; i++)
        list1.ListInsert(i, i);
    std::cout << list1.ListEmpty() << " " << list1.ListLength() << " " << list1.L_size() << std::endl;
    for (int i = 1; i <= list1.ListLength(); i++)
        if (list1.GetElem(i, e1))
            std::cout << e1 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 10; i >= 1; i--)
    {
        if (list1.ListDelete(i, e2))
          std::cout << e2 << " ";
    }
    std::cout << std::endl;
    std::cout << list1.ListEmpty() << " " << list1.ListLength() << " " << list1.L_size() << std::endl;
    for (int i = 1; i <= list1.ListLength(); i++)
        if (list1.GetElem(i, e1))
            std::cout << e1 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 1; i <= 10; i++)
        list1.ListInsert(i, i);
    std::cout << list1.ListEmpty() << " " << list1.ListLength() << " " << list1.L_size() << std::endl;
    std::cout << std::endl;

    for (int i = 11; i >= 1; i--)
        std::cout << list1.LocateElem(i) << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = list1.ListLength(); i >= 1; i--)
        if (list1.PriorElem(i, e2))
          std::cout << e2 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 1; i <= list1.ListLength(); i++)
        if (list1.NextElem(i, e2))
          std::cout << e2 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 1; i<= list1.ListLength(); i++)
        list1.SetElem(i, i * 2);
    std::cout << list1.ListEmpty() << " " << list1.ListLength() << " " << list1.L_size() << std::endl;
    for (int i = 1; i <= list1.ListLength(); i++)
        if (list1.GetElem(i, e1))
            std::cout << e1 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    link_list<int> list2;
    list2.FirstIns(11);
    for (int i = 1; i <= 10; i++)
        list2.ListInsert(i, i);
    std::cout << list2.ListEmpty() << " " << list2.ListLength() << " " << list2.L_size() << std::endl;
    for (int i = 1; i <= list2.ListLength(); i++)
        if (list2.GetElem(i, e1))
            std::cout << e1 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    list2.ClearList();
    std::cout << list2.ListEmpty() << " " << list2.ListLength() << " " << list2.L_size() << std::endl;
    std::cout << std::endl;

    list1.merge_list(list2);
    std::cout << list1.ListEmpty() << " " << list1.ListLength() << " " << list1.L_size() << std::endl;
    for (int i = 1; i <= list1.ListLength(); i++)
        if (list1.GetElem(i, e1))
            std::cout << e1 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    list2.FirstIns(11);
    for (int i = 1; i <= 10; i++)
        list2.ListInsert(i, i);
    list1.merge_list(list2);
    std::cout << list1.ListEmpty() << " " << list1.ListLength() << " " << list1.L_size() << std::endl;
    for (int i = 1; i <= list1.ListLength(); i++)
        if (list1.GetElem(i, e1))
            std::cout << e1 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    //链表元素类型为char型
    link_list<char> list3;
    char e3, e4;
    std::cout << list3.ListEmpty() << " " << list3.ListLength() << " " << list3.L_size() << std::endl;
    std::cout << std::endl;

    if (list3.FirstIns('a'))
    {
        std::cout << list3.ListEmpty() << " " << list3.ListLength() << " " << list3.L_size() << std::endl;
        for (int i = 1; i <= list3.ListLength(); i++)
            if (list3.GetElem(i, e3))
                std::cout << e3 << " ";
        std::cout << std::endl;
        std::cout << std::endl;
    }

    if (list3.AppendElem('b'))
    {
        std::cout << list3.ListEmpty() << " " << list3.ListLength() << " " << list3.L_size() << std::endl;
        for (int i = 1; i <= list3.ListLength(); i++)
            if (list3.GetElem(i, e3))
                std::cout << e3 << " ";
        std::cout << std::endl;
        std::cout << std::endl;
    }

    if (list3.FirstDel(e4))
    {
        std::cout << list3.ListEmpty() << " " << list3.ListLength() << " " << list3.L_size() << std::endl;
        std::cout << e4 << std::endl;
        for (int i = 1; i <= list3.ListLength(); i++)
            if (list3.GetElem(i, e3))
                std::cout << e3 << " ";
        std::cout << std::endl;
        std::cout << std::endl;
    }

    if (list3.RemoveElem(e4))
    {
        std::cout << list3.ListEmpty() << " " << list3.ListLength() << " " << list3.L_size() << std::endl;
        std::cout << e4 << std::endl;
        for (int i = 1; i <= list3.ListLength(); i++)
            if (list3.GetElem(i, e3))
                std::cout << e3 << " ";
        std::cout << std::endl;
        std::cout << std::endl;
    }

    list3.FirstIns('z' + 1);
    for (char c = 'a'; c <= 'z'; c++)
        list3.ListInsert(c - 'a' + 1, c);
    std::cout << list3.ListEmpty() << " " << list3.ListLength() << " " << list3.L_size() << std::endl;
    for (int i = 1; i <= list3.ListLength(); i++)
        if (list3.GetElem(i, e3))
            std::cout << e3 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = list3.ListLength() - 1; i >= 1; i--)
    {
        if (list3.ListDelete(i, e4))
            std::cout << e4 << " ";
    }
    std::cout << std::endl;
    std::cout << list3.ListEmpty() << " " << list3.ListLength() << " " << list3.L_size() << std::endl;
    for (int i = 1; i <= list3.ListLength(); i++)
        if (list3.GetElem(i, e3))
            std::cout << e3 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    for (char c = 'a'; c <= 'z'; c++)
        list3.ListInsert(c - 'a' + 1, c);
    std::cout << list3.ListEmpty() << " " << list3.ListLength() << " " << list3.L_size() << std::endl;
    std::cout << std::endl;

    for (char c = 'z'; c >= 'a'; c--)
        std::cout << list3.LocateElem(c) << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = list3.ListLength(); i >= 1; i--)
        if (list3.PriorElem(i + 'a' - 1, e4))
            std::cout << e4 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 1; i <= list3.ListLength(); i++)
        if (list3.NextElem(i + 'a' - 1, e4))
            std::cout << e4 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 1; i <= list3.ListLength(); i++)
        list3.SetElem(i, i - 1 + 'A');
    std::cout << list3.ListEmpty() << " " << list3.ListLength() << " " << list3.L_size() << std::endl;
    for (int i = 1; i <= list3.ListLength(); i++)
        if (list3.GetElem(i, e3))
            std::cout << e3 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    link_list<char> list4;
    list4.FirstIns('z' + 1);
    for (char c = 'a'; c <= 'z'; c++)
        list4.ListInsert(c - 'a' + 1, c);
    std::cout << list4.ListEmpty() << " " << list4.ListLength() << " " << list4.L_size() << std::endl;
    for (int i = 1; i <= list4.ListLength(); i++)
        if (list4.GetElem(i, e3))
            std::cout << e3 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    list4.ClearList();
    std::cout << list4.ListEmpty() << " " << list4.ListLength() << " " << list4.L_size() << std::endl;
    std::cout << std::endl;

    list3.merge_list(list4);
    std::cout << list3.ListEmpty() << " " << list3.ListLength() << " " << list3.L_size() << std::endl;
    for (int i = 1; i <= list3.ListLength(); i++)
        if (list3.GetElem(i, e3))
            std::cout << e3 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    list4.FirstIns('z' + 1);
    for (char c = 'a'; c <= 'z'; c++)
        list4.ListInsert(c - 'a' + 1, c);
    list3.merge_list(list4);
    std::cout << list3.ListEmpty() << " " << list3.ListLength() << " " << list3.L_size() << std::endl;
    for (int i = 1; i <= list3.ListLength(); i++)
        if (list3.GetElem(i, e3))
            std::cout << e3 << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    system ("pause");
    return 0;
}