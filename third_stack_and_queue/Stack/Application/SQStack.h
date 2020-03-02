
//SQStack.h 与之前编写的一致，以此为基础编写应用实例
#ifndef _SQSTACK_H
#define _SQSTACK_H

#include <iostream>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

template <class SElem>
class SQStack
{
public:
    //SQStack() {} //默认构造函数
    SQStack(int ssize = STACK_INIT_SIZE)
    {
        base = (SElem *)malloc(ssize * sizeof(SElem));
        if (!base)
            exit(1);
        top = base;
        stacksize = ssize;
    }                              //构造函数，构造一个空栈
    ~SQStack() { DestroyStack(); } //析构函数

    void DestroyStack()
    {
        free(base);
        base = top = NULL;
        stacksize = 0;
    } //销毁栈S，S不再存在

    void ClearStack() { top = base; } //把S置为空栈

    bool StackEmpty() { return base == top; } //若栈为空，返回true，否则返回false

    int StackLength() { return top - base; } //返回S的元素个，即栈的长度

    bool GetTop(SElem &e)
    {
        if (!StackEmpty())
        {
            e = *(top - 1);
            return true;
        }
        return false;
    } //若栈不空，用e返回栈顶元素，并返回true,否则返回false

    bool Push(SElem e); //插入元素e为新的栈顶元素

    bool Pop(SElem &e)
    {
        if (GetTop(e))
        {
            top--;
            return true;
        }
        return false;
    } //若栈不空，则删除栈顶元素，并用e返回，返回true,否则返回false

private:
    SElem *base;
    SElem *top;
    int stacksize;
};

template <class SElem>
bool SQStack<SElem>::Push(SElem e)
{
    if (top - base >= stacksize)
    {
        base = (SElem *)realloc(base, (stacksize + STACKINCREMENT) * sizeof(SElem));
        if (!base)
            exit(1);
        top = base + stacksize;
        stacksize += STACKINCREMENT;
    }
    *top = e;
    top++;
    return true;
}

#endif