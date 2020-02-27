

#ifndef _LINK_LIST_H
#define _LINK_LIST_H

#include <iostream>

template<class ElemType> 
struct LNode
{
    ElemType data;
    LNode *next;
};

template<class ElemType>
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
 
  protected:
    void FreeNode(LNode *&lnode1); //释放lnode1所指向的结点

    void MakeNode(LNode *&lnode1); //分配由lnode1指向的结点

    void MakeNode(T e, LNode *&lnode1); //分配由lnode1指向的值为e的结点

  public:
    void ClearList(); //置为空表

    bool ListEmpty()
    {
        return (head->next)? false : true;
    } //判断是否为空表

    int ListLength(); //返回数据元素的个数

    int L_size() 
    {
        return ListLength(); 
    } //返回表的长度

  //以下为书中所要实现的功能
  public:
    bool InsFirst (LNode *p); //将p所指的单个结点插入在第一个结点之前

    bool DelFirst (LNode *&p); //删除链表中的第一个结点并以p返回

    bool Append (LNode *p); //将p所指的一串结点链接在本链表之后

    bool Remove (LNode *&q); //删除链表中的尾结点并以q返回

    void InsBefore (LNode *&p, LNode *q); //p存在，将q所指结点插入在p所指结点之前，并修改指针p指向新插入的结点

    void InsAfter (LNode *&p, LNode *q); //p存在，将q所指结点插入在p所指结点之后，并修改指针p指向新插入的结点

    void SetCurElem (LNode *&p, T e)
    {
        p->data = e;
    } //用e更新p所指结点中数据元素的值

    T GetCurElem(LNode *p)
    {
        return p->data;
    } //返回p所指结点中数据元素的值

    LNode *GetHead()
    {
        return head;
    } //返回线性链表中头结点的位置

    LNode *GetLast(); //返回最后一个结点的位置

    LNode * PriorPos (LNode *p); //返回p所指结点的直接前驱的位置，若无前驱，则返回NULL

    LNode * NextPos (LNode *p)
    {
        if (!p->next)
          return NULL;
        return p->next;
    } //返回p所指结点的直接后继的位置，若无后继，则返回NULL

    bool LocatePos (int i, LNode *&p); //返回p，指示链表中第i个结点的位置。i不合法时返回false

    LNode *LocateElem_p(T e); //在线性表中找出与e相等关系的数据元素的位置，返回第一个元素的位置。不存在返回NULL

  //以下public为上述的函数的对应版本，均是得到元素值，而不是返回位置
  public:
    bool GetElem(int i, T &e); //用e返回第i个元素的值，第1个元素表示头结点之后的下一个元素

    int LocateElem(T e); //在线性表中找出与e相等关系的数据元素的位序，返回第一个元素的位置。存在返回i的下标，不存在返回-1

    bool PriorElem(T cur, T &pri); //返回元素cur的前驱

    bool NextElem(T cur, T &nex); //返回元素cur的后继

    bool ListInsert(int i, T e); //在第i个位置之前插入值e

    bool ListDelete(int i, T &e); //删除第i个位置的元素，并用e返回

    bool FirstIns(T e); //将元素值e插入在第一个结点之前

    bool FirstDel(T &e); //删除链表中的第一个结点并将元素值以e返回

    bool AppendElem(T e); //将元素值e插入在本链表之后

    bool RemoveElem(T &e); //删除链表中的尾结点并以e返回元素值

    bool SetElem(int i, T e); //用e更新第i个结点中数据元素的值

    void merge_list(link_list<T> &llist1); //简单合并，仅将第二个链表连接到第一个链表末尾

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
int link_list<T>::ListLength ()
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
bool link_list<T>::GetElem (int i, T &e)
{
    LNode *p;
    if (LocatePos (i, p))
      e = GetCurElem(p);
    else 
      return false;
    return true;
}

template <class T>
int link_list<T>::LocateElem (T e)
{
    if (!head->next)
      return -1;
    LNode *temp = head->next;
    int j = 1;
    while (temp)
    {
        if (temp->data == e)
          return j;
        temp = temp->next;
        j++;
    }
    return -1;
}

template <class T>
bool link_list<T>::PriorElem (T cur, T &pri)
{
    LNode *cur_p, *pri_p;
    if (cur_p = LocateElem_p (cur))
    {      
      if (pri_p = PriorPos (cur_p))
      {
        if (pri_p == head)
          return false;    
        pri = pri_p->data;
        return true;
      } 
    }
    return false;
}

template <class T>
bool link_list<T>::NextElem(T cur, T &nex)
{
    LNode *cur_p, *nex_p;
    if (cur_p = LocateElem_p(cur))
    {
        if (nex_p = NextPos (cur_p))
        {
            nex = nex_p->data;
            return true;
        }
    }
    return false;
}

template <class T>
bool link_list<T>::ListInsert (int i, T e)
{
    LNode *p;
    if (LocatePos (i, p))
    {
        LNode *q;
        MakeNode (e, q);
        InsBefore (p, q);
        return true;
    }
    return false;
}

template <class T>
bool link_list<T>::ListDelete (int i, T &e)
{
    LNode *p;
    if (LocatePos (i, p))
    {
        LNode *q;
        if (q = PriorPos (p))
        {
            e = p->data;
            q->next = p->next;
            FreeNode(p);
            return true;
        }
    }
    return false;
}

template <class T>
bool link_list<T>::InsFirst(LNode *p)
{
    p->next = head->next;
    head->next = p;
    return true;
}

template <class T>
bool link_list<T>::DelFirst (LNode *&p)
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
    LNode *temp = GetLast(), *pri = PriorPos (temp);
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
typename link_list<T>::LNode * link_list<T>::GetLast()
{
    LNode *temp = head;
    while (temp->next)
      temp = temp->next;
    return temp;
}

template <class T>
typename link_list<T>::LNode * link_list<T>::PriorPos(LNode *p)
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
typename link_list<T>::LNode * link_list<T>::LocateElem_p(T e)
{
    LNode *temp = head->next;
    while (temp)
    {
        if (temp->data == e)
          return temp;
        temp = temp->next;
    }
    return NULL;
}

template <class T>
bool link_list<T>::FirstIns(T e)
{
    LNode *p;
    MakeNode (e, p);
    if (InsFirst(p))
      return true;
    return false;
}

template <class T>
bool link_list<T>::FirstDel(T &e)
{
    LNode *p;
    if (DelFirst (p))
    {
        e = GetCurElem (p);
        FreeNode (p);
        return true;
    }
    return false;
}

template <class T>
bool link_list<T>::AppendElem(T e)
{
    LNode *p;
    MakeNode(e, p);
    if (Append(p))
        return true;
    return false;
}

template <class T>
bool link_list<T>::RemoveElem(T &e)
{
    LNode *p;
    if (Remove(p))
    {
        e = GetCurElem(p);
        FreeNode(p);
        return true;
    }
    return false;
}

template <class T>
bool link_list<T>::SetElem(int i, T e)
{
    LNode *p;
    if (LocatePos (i, p))
    {
        SetCurElem (p, e);
        return true;
    }
    return false;
}

template <class T>
void link_list<T>::merge_list(link_list<T> &llist1)
{
    LNode *p = GetLast(), *q = llist1.GetHead();
    p->next = q->next;
    q->next = NULL;
}

#endif