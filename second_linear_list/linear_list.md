### 2. Linear List
***

- 线性结构的特点是：在数据元素的非空有限集合，
  1. 存在惟一的被称做“第一个”的数据元素；
  2. 存在惟一的一个被称做“最后一个”的数据元素；
  3. 除第一个之外，集合中的每个数据元素均只有一个前驱；
  4. 除最后一个之外，集合中的每个数据元素均只有一个后继。
- **线性表(linear_list)** 是最常用且最简单的一种数据结构，简言之，一个线性表是*n*个数据元素的有限序列。
- 在稍复杂的线性表中，一个数据元素可以由若干个**数据项(item)**组成。在这种情况下，常把数据元素称为**记录(record)**，含有大量记录的线性表又称**文件(file)**。
- 抽象数据类型线性表的定义如下：
```
ADT List {
  数据对象：
  数据关系：
  基本操作：
    InitList (&L) 
    DestroyList (&L) 
    ClearList (&L) 
    ListEmpty (L)
    ListLength (L)
    GetElem (L, i, &e)
    LocateElem (L, e, compare())
    PriorElem (L, cur-e, &pre-e)
    NextElem (L, cur-e, &next-e)
    ListInsert (&L, i, e)
    ListDelete (&L, i, &e)
    ListTraverse (L, visit())
}ADT List
```

#### 线性表的顺序表示和实现
***
* 线性表的顺序表示指的是用一组地址连续的存储单元依次存储线性表的数据元素。
```
//线性表的动态分配顺序存储结构
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct {
  ElemType *elem;
  int length;
  int listsize;
}SqList;
```

