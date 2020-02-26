
#ifndef _SQLIST_1_H
#define _SQLIST_1_H

#include <iostream>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

template <class ElemType>
class sqList
{
  public:
    typedef ElemType T;
    sqList(int lsize = LIST_INIT_SIZE) 
    { 
      elem = (T *) malloc (lsize * sizeof (T));
      length = 0; 
      listsize = lsize; 
    } //构造函数，构造一个空的线性表

    ~sqList() 
    { 
      free(elem); 
      elem = NULL;
    } //析构函数，销毁线性表

    //sqList(sqList &sq1);

    //sqList& operator= (sqList &sq1);

    //sqList& operator[] (cosnt int num);

    void ClearList() 
    {
       length = 0; 
    } //置为空表

    bool ListEmpty()
    {
      return length == 0;
    } //为空表，返回TRUE，否则返回FALSE

    int ListLength()
    {
      return length;
    } //返回数据元素的个数

    int  L_Size()
    {
      return listsize;
    } //返回表的长度

    bool GetElem(int i, T *e)
    {
      if (i < 0 || i >= length)
        return false;
      *e = *(elem + i);
      return true;
    } //返回第i个数据元素的值
      //i从0开始，第0个元素表示第一个值

    int LocateElem (T *e)
    {
      for (int i = 0; i < length; i++)
      {
        if (*(elem + i) == *e)
          return i;
      }
      return -1;
    } //在线性表中找出与*e相等关系的数据元素的位序，返回第一个元素的位置。存在返回i的下标，不存在返回-1

    bool PriorElem (T *cur, T *prior_e)
    {
      int i = LocateElem (cur);
      if (i <= 0) 
        return false;
      else
        *prior_e = *(elem + i - 1);
      return true;
    } //返回元素*cur的前驱
    
    bool NextElem (T *cur, T *next_e)
    {
      int i = LocateElem (cur);
      if (i < 0 || i >= length)
        return false;
      else
        *next_e = *(elem + i + 1);
      return true;
    }

    T * r_alloc (T *e, int incr = LISTINCREMENT)
    {
      T *new_e = (T *)realloc(elem, (listsize + incr) * sizeof(*e));
      if (!new_e)
        exit (1);
      return new_e;
    }

    bool ListInsert (int i, T *e)
    {
      if (i < 0 || i > length)
        return false;
      if (length >= listsize)
      {
        elem = r_alloc(elem);
        listsize += LISTINCREMENT; //每次插入一个元素，默认增长为10  
      }
      for (int j = length; j > i; j--)
        *(elem + j) = *(elem + j - 1);
      *(elem + i) = *e;
      ++length;
      return true;
    } //在顺序表的第i个元素之前插入新的元素*e

    bool ListDelete (int i, T *e)
    {
      if (i < 0 || i >= length)
        return false;
      *e = *(elem + i);
      for (int j = i; j < length - 1; j++)
        *(elem + j) = *(elem + j + 1);
      --length;
      return true;
    } //删除顺序表的第i个元素，并用*e返回其值。

  void merge_sq (sqList<T> &sq_2) //合并两个线性表，未排序，直接插入到第一个的末尾
  {
    for (int i = 0; i < sq_2.ListLength(); i++)
    {
      T T1;
      sq_2.GetElem(i, &T1);
      ListInsert(length, &T1);
    }
  }


private:
  T *elem;
  int length;
  int listsize;
};


#endif