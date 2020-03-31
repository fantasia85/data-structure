//在顺序表中进行顺序查找

#include <iostream>
#include <vector>  //以vector作为顺序表的存储结构

int Search_seq(std::vector<int> &ST, int key); //设置“哨兵”，在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为该元素在
                                               //表中的位置（以1作为起始下标），否则返回0

int main()
{
    std::vector<int> ST;
    ST.push_back(0); //第0个元素预留为“哨兵”
    int num, length;
    std::cout << "Enter length: ";
    std::cin >> length;
    std::cout << "Enter nums:";
    for (int i = 0; i < length; i++)
    {
        std::cin >> num;
        ST.push_back(num);
    }
    std::cout << "Enter key:";
    int key;
    std::cin >> key;
    ST[0] = key;   //“哨兵”
    int pos = Search_seq(ST, key);

    std::cout << "Pos: " << pos << std::endl << std::endl;

    system ("pause");
    return 0;
}

int Search_seq(std::vector<int> &ST, int key)
{
    int i = ST.size() - 1;
    while (ST[i] != key)
        --i;
    return i;
}