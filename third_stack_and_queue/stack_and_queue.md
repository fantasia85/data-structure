### 3.Stack and Queue
***
* 从数据结构角度看，栈和队列也是线性表，其特殊性在于栈和队列的基本操作是线性表操作的子集，它们是操作受限的线性表，因此，可称为限定性数据结构。但是从数据类型的角度看，它们是和线性表大不相同的两类重要的抽象数据类型。

#### Stack
***
* **栈（stack）** 是限定仅在表尾进行插入或删除操作的线性表。因此，对栈来说，表尾端有其特殊含义，称为**栈顶（top）** ，相应地，表头端称为**栈底（bottom）** 。不含元素的空表称为空栈。
* 栈又称为**后进先出（last in first out）** 的线性表（简称**LIFO** 结构）。
* 称插入元素的操作为入栈，删除栈顶元素的操作为出栈。
```
ADT Stack
{
  基本操作：
    InitStack(&S)
    DestroyStack(&S)
    ClearStack(&S)
    StackEmpty(S)
    StackLength(S)
    GetTop(S,&e)
    Push(&S,e)
    Pop(&S,&e)
    StackTraverse(S,visit())
}ADT Stack
```
* 栈的两种形式：顺序栈和链栈
  * [顺序栈SQStack](https://github.com/fantasia85/data-structure/tree/master/third_stack_and_queue/Stack/SQStack)