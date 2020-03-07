//循环队列
#ifndef _SQQueue_H
#define _SQQueue_H

#include <iostream>

#define Queue_SIZE 100

template <class SElem>
class SQQueue
{
    public:
        //SQQueue() {} //默认构造函数
        SQQueue(int qsize = Queue_SIZE) 
        {
            base = (SElem *)malloc(qsize * sizeof(SElem));
            if (!base)
                exit(1);
            front = 0;
            rear = 0;
        }                              //构造函数，构造一个空队列
        ~SQQueue() { } //析构函数

        void ClearQueue () { front = rear = 0; } //把队列置为空队列

        bool QueueEmpty() { return rear - front == 0; } //若队列为空，返回true，否则返回false

        int QueueLength() { return (rear - front + Queue_SIZE) % Queue_SIZE; } //返回队列的元素个数，即队列的长度

        bool GetHead (SElem &e) 
        { 
            if (!QueueEmpty())
            {
                e = *(base + front);
                return true;
            } 
            return false;
        } //若队列不空，用e返回队列头元素，并返回true,否则返回false

        bool EnQueue (SElem e)
        {
            if ((rear + 1) % Queue_SIZE == front)
                return false;
            *(base + rear) = e;
            rear = (rear + 1) % Queue_SIZE;
            return true;
        } //插入元素e为新的队尾元素

        bool DeQueue (SElem &e) 
        {
            if (GetHead(e))
            {
                front = (front + 1) % Queue_SIZE;
                return true;
            }
            return false;
        } //若队列不空，则删除队列头元素，并用e返回，返回true,否则返回false


    private:
        SElem *base;
        int front;
        int rear;
};

#endif