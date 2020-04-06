//表插入排序

#include <iostream>
#include <vector>  //用来存储静态链表

struct SLNode   //表结点类型
{
    int rc; //记录项
    int next;  //指针项
};

void MakeSL(std::vector<SLNode> &SL); //表插入排序

void ArrangeSL(std::vector<SLNode> &SL); //重排表中记录

int main()
{
    int length;
    std::cout << "Enter length: ";   //直接输入长度，方便输入
    std::cin >> length;
    std::vector<SLNode> SL(length + 1);  //0号单元为表头结点

    MakeSL(SL);
    ArrangeSL(SL);

    std::cout << "Numbers after arranging: " << std::endl;
    for (int i = 1; i < length + 1; i++)
        std::cout << SL[i].rc << " ";
    std::cout << std::endl;

    system ("pause");
    return 0;
}

void MakeSL(std::vector<SLNode> &SL)
{
    int len = SL.size();
    std::cout << "Enter numbers: ";
    std::cin >> SL[1].rc;
    SL[1].next = 0;
    SL[0].rc = INT_MAX;
    SL[0].next = 1;    //先将表中第一个元素和表头元素构成一个循环
    for (int i = 2; i < len; i++)
    {
        std::cin >> SL[i].rc;
        int cur = SL[0].next;
        int last = 0;
        while (SL[cur].rc < SL[i].rc)
        {
            last = cur;
            cur = SL[cur].next;   
        }
        SL[last].next = i;
        SL[i].next = cur;  //插入后，修改插入位置之前元素的下一个元素的位置，并修改当前元素的下一个元素位置
    }
}

void ArrangeSL(std::vector<SLNode> &SL)
{
    int len = SL.size();
    int cur = SL[0].next;
    for (int i = 1; i < len; i++)   //第i个记录的位置应该不小于i
    {
        while (cur < i) //找到第i个记录，并用cur指示其在SL中当前位置
            cur = SL[cur].next;
        int nex = SL[cur].next;   //当前元素的下一个元素的位置
        if (cur != i)
        {
            int temp = SL[cur].rc;
            SL[cur].rc = SL[i].rc;
            SL[cur].next = SL[i].next;  //交换记录，使第i个记录在第i个位置上
            SL[i].rc = temp;  
            SL[i].next = cur;  //指向被移走的记录，使得之后可以再次被循环找回
        }
        cur = nex;  //cur指向之前元素的下一个元素位置，为寻找第i+1个元素做准备
    }
}