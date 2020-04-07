//冒泡排序

#include <iostream>
#include <vector>

void Bubblesort(std::vector<int> &BS); //起泡排序

int main()
{
    int length;
    std::cout << "Enter the length: ";
    std::cin >> length;
    int num;
    std::vector<int> BS;
    std::cout << "Enter num: ";
    for (int i = 0; i < length; i++)
    {
        if (std::cin >> num)
            BS.push_back(num);
    }
    Bubblesort(BS);

    std::cout << "Number after sorting: ";
    for (int i = 0; i < length; i++)
        std::cout << BS[i] << " ";
    std::cout << std::endl;

    system ("pause");
    return 0;
}

void Bubblesort(std::vector<int> &BS)
{
    int len = BS.size() - 1;
    for (int i = len; i > 0; i--)
    { 
        bool change = false;   //用来检查在一趟起泡排序过程中是否交换过元素
        for (int j = 1; j <= i; j++)   //一趟起泡排序
        {
            if (BS[j] < BS[j - 1])  //当后一个元素比前一个元素小时，交换两个元素的位置
            {
                int temp = BS[j];
                BS[j] = BS[j - 1];
                BS[j - 1] = temp;
                change = true;  
            }
        }
        if (!change)  //若在一趟排序过程中没有进行过交换记录的操作，表示排序已经完成
            break;
    }
}