#ifndef _LLSTACK_H
#define _LLSTACK_H

#include "link_list_3.h"
#include <iostream>

template <class SElem>
class LLStack
{
public:
    typedef SElem T;
    typedef LNode<T> LNode;
    typedef link_list<T> link_list;

    LNode *base() { return ls.GetHead(); }

    LNode *top() { return ls.GetLast(); }

    //LLStack () {} //默认构造函数

    //~LLStack() {}; //析构函数

    void ClearStack() { ls.ClearList(); } //把S置为空栈

    bool StackEmpty() { return base() == top(); } //若栈为空，返回true，否则返回false

    int StackLength() { return ls.ListLength(); } //返回S的元素个，即栈的长度

    bool GetTop(SElem &e)
    {
        if (!StackEmpty())
        {
            e = ls.GetCurElem(top());
            return true;
        }
        return false;
    } //若栈不空，用e返回栈顶元素，并返回true,否则返回false

    bool Push(SElem e)
    {
        LNode *temp;
        ls.MakeNode(e, temp);
        if (ls.Append(temp))
            return true;
        return true;
    } //插入元素e为新的栈顶元素

    bool Pop(SElem &e)
    {
        if (GetTop(e))
        {
            LNode *temp = top();
            ls.Remove(temp);
            return true;
        }
        return false;
    } //若栈不空，则删除栈顶元素，并用e返回，返回true,否则返回false

private:
    link_list ls;
};

#endif