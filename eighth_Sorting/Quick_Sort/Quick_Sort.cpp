//快速排序

#include <iostream>
#include <vector>

void Quicksort1(std::vector<int> &L, int low, int high); //快速排序算法，low和high表示区间

int Partitionsort1(std::vector<int> &L, int low, int high); //一趟快速排序

int main()
{
    std::vector<int> L;
    int length;
    std::cout << "Enter length: ";
    std::cin >> length;
    std::cout << "Enter number: ";
    for (int i = 0; i < length; i++)
    {
        int num;
        if (std::cin >> num)
            L.push_back(num);
    }

    Quicksort1(L, 0, length - 1);

    std::cout << "Number after sort: ";
    for (int i = 0; i < length; i++)
        std::cout << L[i] << " ";
    std::cout << std::endl;

    system ("pause");
    return 0;
}

void Quicksort1(std::vector<int> &L, int low, int high)
{
    if (low < high)  //长度大于1
    {
        int pos = Partitionsort1(L, low, high);  //将一个区间分为两个
        Quicksort1(L, low, pos - 1);  //对低子表递归排序
        Quicksort1(L, pos + 1, high);  //对高子表递归排序
    }
}

int Partitionsort1(std::vector<int> &L, int low, int high)
{
    int temp = L[low];  //用temp记录枢轴的值
    while (low < high)   //从表两端交替地向中间扫描
    {
        while (low < high && L[high] >= temp)
            high--;
        L[low] = L[high];   //较小的记录移到低端
        while (low < high && L[low] <= temp)
            low++;
        L[high] = L[low];  //较大的记录移到高端
    }
    L[low] = temp;  //枢轴位置记录到位
    return low;  //返回枢轴的位置
}