//堆排序

#include <iostream>
#include <vector>

void HeapAdjust(std::vector<int> &H, int s, int m);  
//已知H[s...m]中记录的关键字除H[s]之外均满足堆的定义，本函数调整H[s]的关键字，
//使H[s...m]成为一个大顶堆（对其中记录的关键字而言）

void HeapSort(std::vector<int> &H);
//对顺序表H进行堆排序

int main()
{
    int length;
    std::cout << "Enter length: ";
    std::cin >> length;
    std::vector<int> H;
    int num;
    std::cout << "Enter number: ";
    for (int i = 0; i < length; i++)
    {
        if (std::cin >> num)
            H.push_back(num);
    }

    HeapSort(H);

    std::cout << "Number after sorting: ";
    for (int i = 0; i < length; i++)
        std::cout << H[i] << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}

void HeapSort(std::vector<int> &H)
{
    for (int i = H.size() / 2 - 1; i >= 0; i--)  //首先把H[0...H.size()-1]建成大顶堆
        HeapAdjust(H, i, H.size() - 1);
    for (int i = H.size() - 1; i > 0; i--)
    {
        int temp = H[i];    //将堆顶元素和未经排序子序列中的最后一个记录相互交换
        H[i] = H[0];
        H[0] = temp;
        HeapAdjust(H, 0, i - 1);   //重新调整为大顶堆
    }
}

void HeapAdjust(std::vector<int> &H, int s, int m)
{
    int cur = H[s];
    for (int i = s * 2 + 1; i <= m; i = i * 2 + 1)  //沿key较大的孩子结点向下筛选
    {
        if (i < m && H[i] < H[i + 1])  //i指向两者中元素值较大的下标
            i++;
        if (cur >= H[i])  //cur插入在原来的位置上
            break;
        H[s] = H[i];  //交换元素值和下标
        s = i;
    }
    H[s] = cur;  //为下标为s的元素赋值
}