//折半插入排序

#include <iostream>
#include <vector> //用来存储数据

void BInsertSort(std::vector<int> &v1); //折半插入排序（不设置哨兵）

int main()
{
    std::vector<int> v1;
    int length; //数据的长度
    std::cout << "The length: ";
    std::cin >> length;
    std::cout << "Enter num: ";
    int num;
    for (int i = 0; i < length; i++)
    {
        std::cin >> num;
        v1.push_back(num);
    }

    BInsertSort(v1);
    std::cout << "The num after sort: " << std::endl;
    for (int n : v1)
        std::cout << n << " ";
    std::cout << std::endl
              << std::endl;

    system("pause");
    return 0;
}

void BInsertSort(std::vector<int> &v1)
{
    for (int i = 1; i < v1.size(); i++)
    {
        if (v1[i] < v1[i - 1]) //需将v1[i]插入到有序子表中
        {
            int temp = v1[i];
            int low = 0, high = i - 1;
            int mid = (low + high) / 2;
            while (low <= high)   //进行折半查找，找到有序插入的位置
            {
                mid = (low + high) / 2;  //折半
                if (v1[mid] < temp)    //插入点在高半区
                    low = mid + 1;
                else    //插入点在低半区
                {
                    high = mid - 1;
                }
            }
            for (int j = i - 1; j >= high + 1; --j) 
                v1[j + 1] = v1[j];   //记录后移
            v1[high + 1] = temp;  //记录插入到指定位置
        }
    }
}