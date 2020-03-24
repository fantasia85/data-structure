//4(8)皇后问题

#include <iostream>
#include <vector>
#include <algorithm>

//i表示第i行，n表示n*n的棋盘，cur表示前i-1行放置的棋子位置信息，argmt存放所有合法的排列
void trial (int i, const int n, std::vector<int> cur, std::vector<std::vector<int>> &argmt);

int main ()
{
    int n;
    std::cout << "Enter num n:";
    std::cin >> n;
    std::vector<int> cur(n, -1);  //棋盘布局用一维数组表示，每一个元素表示对应行的第几个元素
    std::vector<std::vector<int>> argmt; //所有可能的布局用二维数组表示，每一个元素表示一种可能的布局

    trial (0, n, cur, argmt);
    
    //输出，0表示未放置棋子，1表示放置棋子
    std::cout << "Total argmt:" << argmt.size() << std::endl;
    for (std::vector<int> v1 : argmt)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == v1[i])
                    std::cout << 1;
                else
                    std::cout << 0;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl << std::endl;
    }

    system("pause");
    return 0;
}

void trial(int i, const int n, std::vector<int> cur, std::vector<std::vector<int>> &argmt)
{
    if (i >= n)   //i >= n 时，表示已经完成，存入argmt数组
    {
        argmt.push_back(cur);
        return;
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            std::vector<int>::iterator iter1 = find(cur.begin(), cur.end(), j);  //首先不在同一列
            if (iter1 != cur.end())
                continue;
            //同时不在对角线上
            bool diagonal = false;
            for (int tj = j - 1, ti = i - 1; tj >= 0 && ti >= 0; tj--, ti--) //左上对角线
            {
                if (diagonal)
                    break;
                if (cur[ti] == tj)
                    diagonal = true;
            }
            for (int tj = j + 1, ti = i - 1; tj < n && ti >= 0; tj++, ti--) //右上对角线
            {
                if (diagonal)
                    break;
                if (cur[ti] == tj)
                    diagonal = true;
            }
            if (diagonal)
                continue;
            cur[i] = j;
            trial (i + 1, n, cur, argmt);
            cur[i] = -1;
        }
    }
}