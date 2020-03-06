#ifndef _LLQUEUE_H
#define _LLQUEUE_H

#include "link_list_4.h"
#include <iostream>

template <class SElem>
class LLQueue
{
public:
    typedef SElem T;
    typedef LNode<T> LNode;
    typedef link_list<T> link_list;

    LNode *front() { return lq.GetHead(); }  //队头

    LNode *rear() { return lq.GetLast(); } //队尾

    //LLQueue () {} //默认构造函数

    //~LLQueue() {}; //析构函数

    void ClearQueue() { lq.ClearList(); } //置为空队列

    bool QueueEmpty() { return front() == rear(); } //若队列为空，返回true，否则返回false

    int QueueLength() { return lq.ListLength(); } //返回队列的元素个数，即队列的长度

    bool GetHead(SElem &e)
    {
        if (!QueueEmpty())
        {
            e = lq.GetCurElem(lq.NextPos(lq.GetHead()));
            return true;
        }
        return false;
    } //若队列不空，用e返回队头元素，并返回true,否则返回false

    bool EnQueue(SElem e)
    {
        LNode *temp;
        lq.MakeNode(e, temp);
        if (lq.Append(temp))
            return true;
        return true;
    } //插入元素e为新的队尾元素

    bool DeQueue(SElem &e)
    {
        if (!QueueEmpty())
        {
            LNode *temp;
            lq.DelFirst (temp);
            e = lq.GetCurElem(temp);
            lq.FreeNode(temp);
            return true;
        }
        return false;
    } //若队列不空，则删除队头元素，并用e返回，返回true,否则返回false

private:
    link_list lq;
};

#endif