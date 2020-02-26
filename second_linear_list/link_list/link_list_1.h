

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

    ~link_list()
    {
        LNode *cur = head, *nex;
        while (cur)
        {
            nex = cur->next;
            FreeNode(cur);
            cur = nex;    
        }
    } //析构函数，销毁线性表
    
    //link_list(link_list &llist1);

    //link_list& operator= (link_list &llist1);
 
  protected:
    void FreeNode(LNode *lnode1)
    {
        free(lnode1);
        lnode1 = NULL;
    } //释放lnode1所指向的结点

    void MakeNode(Lnode *lnode1)
    {
        lnode1 = (LNode *)malloc(sizeof(LNode));
        lnode1->next = NULL;
    } //分配由lnode1指向的结点

    void MakeNode(T *e, LNode *lnode1)
    {
        lnode1 = (LNode *)malloc(sizeof(LNode));
        lnode1->next = NULL;
        lnode1->data = *e;
    } //分配由lnode1指向的值为*e的结点

  public:
    void ClearList()
    {
        LNode *cur = head->next, *nex;
        while (cur)
        {
            nex = cur->next;
            FreeNode(cur);
            cur = nex;
        }
        head->next = NULL;
    } //置为空表

    bool ListEmpty()
    {
        return (head->next)? false : true;
    } //判断是否为空表

    int ListLength(); //返回数据元素的个数

    int L_size() 
    {
        return ListLength(); 
    } //返回表的长度

    bool GetElem (int i, T *e); //返回第i个元素的值，第1个元素表示头结点之后的下一个元素

    int LocateElem(T *e); //在线性表中找出与*e相等关系的数据元素的位序，返回第一个元素的位置。存在返回i的下标，不存在返回-1

    bool PriorElem(T *cur, T *pri); //返回元素*cur的前驱

    bool NextElem(T *cur, T *nex); //返回元素*cur的后继

    bool ListInsert (int i, T *e); //在第i个位置之前插入值*e
    //未完成

    bool ListDelete (int i, T *e); //删除第i个位置的元素，并用*e返回
    //未完成

    void merge_list (link_list &llist1); //简单合并，仅将第二个链表连接到第一个链表末尾
    //未完成

protected:
    bool InsFirst (LNode *p)
    {
        p->next = head->next;
        head->next = p;
        return true;
    } //将p所指的单个结点插入在第一个结点之前

    bool DelFirst (LNode *&p); //删除链表中的第一个结点并以p返回

    bool Append (LNode *p)
    {
        LNode *temp = head;
        while (temp->next)
          temp = temp->next;
        temp->next = p;
        return true;
    } //将p所指的一串结点链接在本链表之后

    bool Remove (LNode *&q); //删除链表中的尾结点并以q返回

private:
    LNode *head; //头结点
};

template <class T>
int link_list<T>::ListLength ()
{
    if (!head->next)
        return 0;
    LNode *temp = head->next;
    int length = 1;
    while (temp->next)
        length++;
    return length;
}

template <class T>
bool link_list<T>::GetElem (int i, T *e)
{
    int length = ListLength();
    if (i > length)
      return false;
    LNode *temp = head->next;
    i--;
    while (i)
    {
        temp = temp->next;
        i--;
    }
    *e = temp->data;
    return true;
}

template <class T>
int link_list<T>::LocateElem (T *e)
{
    if (!head->next)
      return -1;
    LNode *temp = head->next;
    int j = 1;
    while (temp)
    {
        if (temp->data == *e)
          return j;
        temp = temp->next;
        j++;
    }
    return -1;
}

template <class T>
bool link_list<T>::PriorElem (T *cur, T *pri)
{
    int i = LocateElem (*cur);
    if (i <= 1)
      return false;
    i = i - 1;
    if (GetElem(i, pri))
      return true;
    return false;
}

template <class T>
bool link_list<T>::NextElem(T *cur, T *nex)
{
    int i = LocateElem (*cur);
    if (i < 0 || i >= ListLength())
      return false;
    i = i + 1;
    if (GetElem(i, nex))
      return true;
    return false;
}

template <class T>
bool link_list<T>::ListInsert (int i, T *e)
{
    if (i < 1 || i > ListLength())
        return false;
    else if (i == 1)
    {
        LNode *n_node = (LNode *) malloc (sizeof (LNode));
        n_node->next = head->next;
        n_node->data = *e;
        head->next = n_node->next;    
    }
    else
    {
        
    }
    
}

template <class T>
bool link_list<T>::ListDelete (int i, T *e)
{

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
bool link_list<T>::Remove(LNode *&q)
{
    if (!head->next)
      return false;
    LNode *temp = head, *pri;
    while (temp->next)
    {
        pri = temp;
        temp = temp->next;
    }
    pri->next = NULL;
    q = temp;
    return true;
}

#endif