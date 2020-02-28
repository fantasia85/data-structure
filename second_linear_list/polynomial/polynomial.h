
//在link_list_2.h的基础上进行

#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H

#include "link_list_2.h"
#include <iostream>

struct ElemT //每一项的表示
{
    float coef; //系数
    int expn; //指数

    ElemT () {} //默认构造函数

    ElemT(float f1, int i1) : coef(f1), expn(i1) {}  //构造函数

    bool operator== (const ElemT &e1)
    {
        return expn == e1.expn;
    } //运算符重载

    bool operator< (const ElemT &e1)
    {
        return expn < e1.expn;
    }

    ElemT& operator= (const ElemT &e1)
    {
        coef = e1.coef;
        expn = e1.expn;
        return *this;
    }

    ElemT& Add_Elem (const ElemT &e1)
    {
        coef += e1.coef;
        return *this;
    } //加

    ElemT& Mul_Elem (const ElemT &e1)
    {
        coef *= e1.coef;
        expn += e1.expn;
        return *this;
    } //乘

    ElemT& Minus_Elem (const ElemT &e1)
    {
        coef -= e1.coef;
        return *this;
    } //减
};

class polynomial
{
  public:
    typedef ElemT T;
    typedef LNode<T> LNode;
    typedef link_list<T> link_list;

    void CreatPolyn (int m); //输入m项的系数和指数，建立表示一元多项式的有序链表

    void DestroyPolyn () 
    {
        llst.ClearList();
    } //销毁一元多项式

    bool PolynEmpty()
    {
        return llst.ListEmpty();
    } //判断是否为空多项式

    int PolynLength()
    {
        return llst.ListLength();
    } //返回多项式中的项数

    void PrintPolyn (); //打印输出一元多项式

    void AddPolyn (polynomial &p1); //完成多项式的相加运算

    void SubtractPolyn (polynomial &p1); //完成多项式的相减运算

    void MultiplyPolyn (polynomial &p1); //完成多项式的相乘运算
    //未完成

    void OrderInsert(T e); //将元素值e插入到有序链表中合适的位置上

  //polynomial中对应与link_list_2中的操作
  public: 
    bool InsFirst_P(LNode *p) { return llst.InsFirst(p); } //将p所指的单个结点插入在第一个结点之前

    bool DelFirst_P(LNode *&p) { return llst.DelFirst(p); } //删除链表中的第一个结点并以p返回

    bool Append_P(LNode *p) { return llst.Append(p); } //将p所指的一串结点链接在本链表之后

    bool Remove_P(LNode *&q) { return llst.Remove(q); } //删除链表中的尾结点并以q返回

    void InsBefore_P(LNode *&p, LNode *q) { llst.InsBefore(p, q); } //p存在，将q所指结点插入在p所指结点之前，并修改指针p指向新插入的结点

    void InsAfter_P(LNode *&p, LNode *q) { llst.InsAfter(p, q); } //p存在，将q所指结点插入在p所指结点之后，并修改指针p指向新插入的结点

    void SetCurElem_P(LNode *&p, T e) { llst.SetCurElem (p, e); } //用e更新p所指结点中数据元素的值

    T& GetCurElem_P(LNode *p) { return llst.GetCurElem (p); } //返回p所指结点中数据元素的值

    LNode *GetHead_P() { return llst.GetHead(); } //返回线性链表中头结点的位置

    LNode *GetLast_P() { return llst.GetLast(); } //返回最后一个结点的位置

    LNode *PriorPos_P(LNode *p) { return llst.PriorPos(p); } //返回p所指结点的直接前驱的位置，若无前驱，则返回NULL

    LNode *NextPos_P(LNode *p) { return llst.NextPos(p); }//返回p所指结点的直接后继的位置，若无后继，则返回NULL

    bool LocatePos_P(int i, LNode *&p) { return llst.LocatePos(i, p); } //返回p，指示链表中第i个结点的位置。i不合法时返回false

    bool LocateElem_P(T e, LNode *&p) { return llst.LocateElem_p(e, p); } 
    //在线性表中找出与e相等关系的数据元素的位置，用p返回第一个元素的位置（地址），并返回true。
    //不存在时返回应该插入位置的下一个元素的位置，并返回false。应插入末尾时返回NULL 

    void ListDelete_P(LNode *&p) { return llst.ListDelete(p); } //p存在，删除p结点，并修改指针p指向被删除之后的下一个位置

    void FreeNode_P(LNode *&lnode1) { return llst.FreeNode(lnode1); } //释放lnode1所指向的结点

    void MakeNode_P(LNode *&lnode1) { return llst.MakeNode(lnode1); } //分配由lnode1指向的结点

    void MakeNode_P(T e, LNode *&lnode1) { return llst.MakeNode(e, lnode1); } //分配由lnode1指向的值为e的结点

private:
    link_list llst;
};

void polynomial::OrderInsert (T e)
{
    LNode *p, *nnode;
    if (LocateElem_P(e, p))
    {
        GetCurElem_P(p).Add_Elem(e);
    }
    else 
    {
        MakeNode_P (e, nnode);
        if (p)
            InsBefore_P(p, nnode);
        else
            Append_P(nnode);
    }
}


void polynomial::CreatPolyn (int m)
{
    for (int i = 0; i < m; i++)
    {
        T t1;
        std::cout << i << " coef expn:" ;
        std::cin >> t1.coef >> t1.expn;
        OrderInsert (t1);
    }
}

void polynomial::PrintPolyn()
{
    LNode *cur = GetHead_P();
    bool plussign = false;
    std::cout << "f(x) = ";
    while (cur = NextPos_P(cur))
    {
        if (plussign)
            if (GetCurElem_P(cur).coef > 0)
                std::cout << "+";
        std::cout << GetCurElem_P(cur).coef << "x^" << GetCurElem_P(cur).expn;
        plussign = true;
    }
    std::cout << std::endl << std::endl;
}

void polynomial::AddPolyn(polynomial &p1)
{
    LNode *h = GetHead_P(), *h1 = p1.GetHead_P();
    LNode *q = NextPos_P(h), *q1 = p1.NextPos_P(h1);
    while (q && q1)
    {
        if (GetCurElem_P(q) == p1.GetCurElem_P(q1))
        {
            GetCurElem_P(q).Add_Elem(p1.GetCurElem_P(q1));
            if (GetCurElem_P(q).coef == 0.0 )
            {
                ListDelete_P(q);
                p1.ListDelete_P(q1);
            }
            else 
                p1.ListDelete_P(q1);
        }
        else if (p1.GetCurElem_P(q1) < GetCurElem_P(q))
        {
            LNode *temp = p1.NextPos_P(q1); //先记录下q1的下一位置
            InsBefore_P(q, q1);
            q = NextPos_P (q);
            q1 = temp;
        }
        else 
        {
            NextPos_P(q);
        }
    }
    if (!q1)
    {
        Append_P(q1);
    }
}

void polynomial::SubtractPolyn(polynomial &p1)
{
    LNode *h = GetHead_P(), *h1 = p1.GetHead_P();
    LNode *q = NextPos_P(h), *q1 = p1.NextPos_P(h1);
    while (q && q1)
    {
        if (GetCurElem_P(q) == p1.GetCurElem_P(q1))
        {
            GetCurElem_P(q).Minus_Elem(p1.GetCurElem_P(q1));
            if (GetCurElem_P(q).coef == 0.0)
            {
                ListDelete_P(q);
                p1.ListDelete_P(q1);
            }
            else
                p1.ListDelete_P(q1);
        }
        else if (p1.GetCurElem_P(q1) < GetCurElem_P(q))
        {
            LNode *temp = p1.NextPos_P(q1); //先记录下q1的下一位置
            InsBefore_P(q, q1);
            GetCurElem_P(q).coef = -GetCurElem_P(q).coef; //设为负值，应该有更好的方法
            q = NextPos_P(q);
            q1 = temp;
        }
        else
        {
            NextPos_P(q);
        }
    }
    if (!q1)
    {
        LNode *temp = q1;
        while (temp)
        {
            GetCurElem_P(temp).coef = -GetCurElem_P(temp).coef;
            temp = p1.NextPos_P(temp);
        }
        Append_P(q1);
    }
}

#endif