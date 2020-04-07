//归并排序（2-路归并排序）

#include <iostream>
#include <vector>

void MSort(std::vector<int> SR, std::vector<int> &TR1, int low, int high); //将SR[low...high]归并排序为TR1[low...high]

void Merge1(std::vector<int> TR2, std::vector<int> &TR1,int low, int mid, int high); 
//将TR2[low...mid]和TR2[mid...high]归并到TR1[low...high]

int main()
{
    std::vector<int> TR1;
    int length;
    std::cout << "Enter length: ";
    std::cin >> length;
    int num;
    std::cout << "Enter number: ";
    for (int i = 0; i < length; i++)
    {
        if (std::cin >> num)
            TR1.push_back(num);
    }

    MSort(TR1, TR1, 0, length - 1);
    std::cout << "Number after sorting: ";
    for (int i = 0; i < length; i++)
        std::cout << TR1[i] << " ";
    std::cout << std::endl;

    system("pause");
    return 0;
}

void MSort(std::vector<int> SR, std::vector<int> &TR1, int low, int high)
{
    if (low == high)
        TR1[low] = SR[low];
    else
    {
        int mid = (low + high) / 2;   //将SR平分为两个部分
        //std::vector<int> TR2(SR);
        //MSort(SR, TR2, low, mid);    //递归地将SR[low...mid]归并为有序的TR2[low...mid]
        //MSort(SR, TR2, mid + 1, high);  //递归地将SR[mid+1...high]归并为有序的TR2[mid+1...high]
        //Merge1(TR2, TR1, low, mid, high);  //将TR2[low...mid]和TR2[mid+1...high]归并到TR1[low...high]
        
        MSort(SR, SR, low, mid);    //递归地将SR[low...mid]归并为有序的SR[low...mid]
        MSort(SR, SR, mid + 1, high);  //递归地将SR[mid+1...high]归并为有序的SR[mid+1...high]
        Merge1(SR, TR1, low, mid, high);  //将TR2[low...mid]和TR2[mid+1...high]归并到TR1[low...high]
    }
}

void Merge1(std::vector<int> TR2, std::vector<int> &TR1, int low, int mid, int high)
{
    int i = low, j = mid + 1;
    while (i <= mid && j <= high)   //将TR2中的记录由小到大并入TR1
    {
        if (TR2[i] > TR2[j])
            TR1[low++] = TR2[j++];
        else
            TR1[low++] = TR2[i++];
    }
    while (i <= mid)  //将TR2[low...mid]中剩余记录并入TR2
        TR1[low++] = TR2[i++];
    while (j <= high)  //将TR2[mid+1...high]中剩余记录并入TR2
        TR1[low++] = TR2[j++];
}