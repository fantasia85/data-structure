//直接插入排序

#include <iostream>
#include <vector>  //用来存储数据

void SInsertSort(std::vector<int> &v1); //直接插入排序（不设置哨兵）

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

    SInsertSort(v1);
    std::cout << "The num after sort: " << std::endl;
    for (int n : v1)
        std::cout << n << " ";
    std::cout << std::endl << std::endl;

    system ("pause");
    return 0;
}

void SInsertSort(std::vector<int> &v1)
{
    for (int i = 1; i < v1.size(); i++)
    {
        if (v1[i] < v1[i - 1])  //需将v1[i]插入到有序子表中
        {
            int temp = v1[i];
            int j;
            for (j = i - 1; j >= 0 && v1[j] > temp; j--)
                v1[j + 1] = v1[j];  //记录后移
            v1[j + 1] = temp;
        }
    }
}