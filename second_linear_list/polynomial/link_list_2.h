
//在原先link_list_1.h的基础上进行修改，删去直接得到元素值的操作，并改成有序链表
//重新定义bool LocateElem_p (T e, LNode *&p);使其作用于有序链表
//定义void ListDelete(LNode *p);
#ifndef _LINK_LIST_2_H
#define _LINK_LIST_2_H

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

    int L_size()
    {
        return ListLength();
    } //返回表的长度

    //以下为书中所要实现的功能
public:
    bool InsFirst(LNode *p); //将p所指的单个结点插入在第一个结点之前

    bool DelFirst(LNode *&p); //删除链表中的第一个结点并以p返回

    bool Append(LNode *p); //将p所指的一串结点链接在本链表之后

    bool Remove(LNode *&q); //删除链表中的尾结点并以q返回

    void InsBefore(LNode *&p, LNode *q); //p存在，将q所指结点插入在p所指结点之前，并修改指针p指向新插入的结点

    void InsAfter(LNode *&p, LNode *q); //p存在，将q所指结点插入在p所指结点之后，并修改指针p指向新插入的结点

    void SetCurElem(LNode *&p, T e)
    {
        p->data = e;
    } //用e更新p所指结点中数据元素的值

    T& GetCurElem(LNode *p)
    {
        return p->data;
    } //返回p所指结点中数据元素的值

    LNode *GetHead()
    {
        return head;
    } //返回线性链表中头结点的位置

    LNode *GetLast(); //返回最后一个结点的位置

    LNode *PriorPos(LNode *p); //返回p所指结点的直接前驱的位置，若无前驱，则返回NULL

    LNode *NextPos(LNode *p)
    {
        if (!p->next)
            return NULL;
        return p->next;
    } //返回p所指结点的直接后继的位置，若无后继，则返回NULL

    bool LocatePos(int i, LNode *&p); //返回p，指示链表中第i个结点的位置。i不合法时返回false

    bool LocateElem_p(T e, LNode *&p); //在线性表中找出与e相等关系的数据元素的位置，用p返回第一个元素的位置（地址），并返回true。
                                       //不存在时返回应该插入位置的下一个元素的位置，并返回false。应插入末尾时返回NULL

    void ListDelete(LNode *&p); //p存在，删除p结点，并修改指针p指向被删除之后的下一个位置

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
void link_list<T>::ListDelete(LNode *&p)
{
    LNode *q;
    if (q = PriorPos(p))
    {
        q->next = p->next;
        q = p;
        p = p->next;
        FreeNode(q);
    }
}

template <class T>
bool link_list<T>::InsFirst(LNode *p)
{
    p->next = head->next;
    head->next = p;
    return true;
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
bool link_list<T>::Remove(LNode *&q)
{
    if (!head->next)
        return false;
    LNode *temp = GetLast(), *pri = PriorPos(temp);
    pri->next = NULL;
    q = temp;
    return true;
}

template <class T>
void link_list<T>::InsBefore(LNode *&p, LNode *q)
{
    LNode *temp = PriorPos(p);
    temp->next = q;
    q->next = p;
    p = q;
}

template <class T>
void link_list<T>::InsAfter(LNode *&p, LNode *q)
{
    q->next = p->next;
    p->next = q;
    p = q;
}

template <class T>
typename link_list<T>::LNode *link_list<T>::GetLast()
{
    LNode *temp = head;
    while (temp->next)
        temp = temp->next;
    return temp;
}

template <class T>
typename link_list<T>::LNode *link_list<T>::PriorPos(LNode *p)
{
    if (p == head)
        return NULL;
    LNode *temp = head;
    while (temp->next != p)
        temp = temp->next;
    return temp;
}

template <class T>
bool link_list<T>::LocatePos(int i, LNode *&p)
{
    if (i < 1 || i > ListLength())
        return false;
    LNode *temp = head->next;
    i--;
    while (i)
    {
        temp = temp->next;
        i--;
    }
    p = temp;
    return true;
}

template <class T>
bool link_list<T>::LocateElem_p(T e, LNode *&p)
{
    LNode *temp = head->next;
    while (temp)
    {
        if (temp->data == e)
        {
            p = temp;
            return true;
        }
        else if (e < temp->data)
        {
            p = temp;
            return false;
        }
        temp = temp->next;
    }
    return false;
}

#endif