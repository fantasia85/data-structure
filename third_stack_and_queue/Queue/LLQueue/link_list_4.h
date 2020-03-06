
//就是原先的link_list_2.h，删除部分操作后，实际可以继续简化
#ifndef _LINK_LIST_4_H
#define _LINK_LIST_4_H

#include <iostream>

template <class ElemType>
struct LNode
{
    ElemType data;
    LNode *next;
};

template <class ElemType>
class link_list
{
public:
    typedef ElemType T;
    typedef LNode<T> LNode;

    link_list()
    {
        MakeNode(head);
    } //构造函数，构造一个空表

    ~link_list(); //析构函数，销毁线性表

    //link_list(link_list &llist1);

    //link_list& operator= (link_list &llist1);

public:
    void FreeNode(LNode *&lnode1); //释放lnode1所指向的结点

    void MakeNode(LNode *&lnode1); //分配由lnode1指向的结点

    void MakeNode(T e, LNode *&lnode1); //分配由lnode1指向的值为e的结点

public:
    void ClearList(); //置为空表

    bool ListEmpty()
    {
        return (head->next) ? false : true;
    } //判断是否为空表

    int ListLength(); //返回数据元素的个数

    //以下为书中所要实现的功能
public:
    bool DelFirst(LNode *&p); //删除链表中的第一个结点并以p返回

    bool Append(LNode *p); //将p所指的一串结点链接在本链表之后

    T GetCurElem(LNode *p)
    {
        return p->data;
    } //返回p所指结点中数据元素的值

    LNode *GetHead()
    {
        return head;
    } //返回线性链表中头结点的位置

    LNode *GetLast(); //返回最后一个结点的位置

    LNode *NextPos(LNode *p)
    {
        if (!p->next)
            return NULL;
        return p->next;
    } //返回p所指结点的直接后继的位置，若无后继，则返回NULL

private:
    LNode *head; //头结点
};

template <class T>
link_list<T>::~link_list()
{
    LNode *cur = head, *nex;
    while (cur)
    {
        nex = cur->next;
        FreeNode(cur);
        cur = nex;
    }
}

template <class T>
void link_list<T>::FreeNode(LNode *&lnode1)
{
    free(lnode1);
    lnode1 = NULL;
}

template <class T>
void link_list<T>::MakeNode(LNode *&lnode1)
{
    lnode1 = (LNode *)malloc(sizeof(LNode));
    lnode1->next = NULL;
}

template <class T>
void link_list<T>::MakeNode(T e, LNode *&lnode1)
{
    lnode1 = (LNode *)malloc(sizeof(LNode));
    lnode1->next = NULL;
    lnode1->data = e;
}

template <class T>
void link_list<T>::ClearList()
{
    LNode *cur = head->next, *nex;
    while (cur)
    {
        nex = cur->next;
        FreeNode(cur);
        cur = nex;
    }
    head->next = NULL;
}

template <class T>
int link_list<T>::ListLength()
{
    if (!head->next)
        return 0;
    LNode *temp = head->next;
    int length = 1;
    while (temp->next)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

template <class T>
bool link_list<T>::DelFirst(LNode *&p)
{
    if (!head->next)
        return false;
    p = head->next;
    head->next = p->next;
    p->next = NULL;
    return true;
}

template <class T>
bool link_list<T>::Append(LNode *p)
{
    LNode *temp = GetLast();
    temp->next = p;
    return true;
}

template <class T>
typename link_list<T>::LNode *link_list<T>::GetLast()
{
    LNode *temp = head;
    while (temp->next)
        temp = temp->next;
    return temp;
}

#endif