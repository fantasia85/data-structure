//求n个元素的集合的幂集，集合A的幂集是由集合A的所有子集所组成的集合
//假设以vector表示集合

#include <iostream>
#include <vector>

//A表示集合，B是幂集中的一个元素，powerset是整个幂集
void getpowerset (int i, const std::vector<int> &A, std::vector<int> B, std::vector<std::vector<int>> &powerset);

int main()
{
    std::vector<int> A;
    for (int i = 1; i <= 3; i++)
        A.push_back(i);
    std::vector<int> B;
    std::vector<std::vector<int>> powerset;
    getpowerset(0, A, B, powerset);

    for (std::vector<int> a : powerset)
    {
        for (int i : a)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    system ("pause");
    return 0;
}

void getpowerset (int i, const std::vector<int> &A, std::vector<int> B, std::vector<std::vector<int>> &powerset)
{
    if (i >= A.size())
    {
        powerset.push_back(B);
        return;
    }
    else
    {
        getpowerset(i + 1, A, B, powerset);
        B.push_back(A[i]);
        getpowerset(i + 1, A, B, powerset);
    }
}