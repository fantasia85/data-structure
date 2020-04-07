//简单选择排序

#include <iostream>
#include <vector>

void S_Selectionsort(std::vector<int> &SS); //简单选择排序

int main()
{
    int length;
    std::cout << "Enter length: ";
    std::cin >> length;
    std::vector<int> SS;
    int num;
    std::cout << "Enter number: ";
    for (int i = 0; i < length; i++)
    {
        if (std::cin >> num)
            SS.push_back(num);
    }

    S_Selectionsort(SS);

    std::cout << "Number after sorting: ";
    for (int i = 0; i < length; i++)
        std::cout << SS[i] << " ";
    std::cout << std::endl;

    system ("pause");
    return 0;
}

void S_Selectionsort(std::vector<int> &SS)
{
    int len = SS.size();
    for (int i = 0; i < len; i++)  //选择第i小的元素，并进行交换
    {
        int pos2 = i;  //记录最小元素的下标
        int min = SS[i];
        for (int j = i + 1; j < len; j++)
        {
            if (SS[j] < min)  //找到最小的元素
            {
                min = SS[j];
                pos2 = j;
            }
        }
        int temp = SS[i];  //交换记录
        SS[i] = SS[pos2];
        SS[pos2] = temp;
    }
}