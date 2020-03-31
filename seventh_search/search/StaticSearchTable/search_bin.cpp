//有序表的折半查找法

#include <iostream>
#include <vector>

int search_bin(std::vector<int> &ST, int key); //在有序表ST中折半查找其关键字等于key的传数据元素，若找到，则函数值为该元素在
                                                //表中的位置（以0作为起始下标），否则返回-1

int main()
{
    std::vector<int> ST;
    int length, num;
    std::cout << "Enter length: ";
    std::cin >> length;
    std::cout << "Enter nums:";
    for (int i = 0; i < length; i++)
    {
        std::cin >> num;
        ST.push_back(num);
    }
    int key;
    std::cout << "Enter key:";
    std::cin >> key;
    int pos = search_bin(ST, key);

    std::cout << "Pos: " << pos << std::endl;

    system("pause");
    return 0;
}

int search_bin(std::vector<int> &ST, int key)
{
    int low = 0, high = ST.size() - 1;   //设置区间初值
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (ST[mid] == key)
            return mid;
        else if (ST[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}