//并查集
/* 最小生成树
 * 样例为找到属于同一个区域（相连）的点，升序排列
 * 样例输入
 * 7 5
 * 0 4
 * 1 2
 * 2 3
 * 5 6
 * 4 5
 * 样例输出
 * 0 4 5 6
 * 1 2 3
 * */

#include <iostream>
#include <vector>

std::vector<int> points;

//并集的操作
void unionfind(int father, int child) {
    points[child] = father;
}

//查找的操作
int findfather(int node) {
    if (points[node] == node)
        return node;
    else {
        //对路径进行压缩
        return points[node] = findfather(points[node]);    
    }
}

int main()
{
    int N, P;
    std::cin >> N >> P;

    points = std::vector<int> (N);
    for (int i = 0; i < N; ++i)
        points[i] = i;

    std::vector<int> cnnt(2);
    for (int i = 0; i < P; ++i) {
        std::cin >> cnnt[0] >> cnnt[1];
        int fth1 = findfather(cnnt[0]);
        int fth2 = findfather(cnnt[1]);
        if (fth1 > fth2)
            unionfind(fth2, fth1);
        else
            unionfind(fth1, fth2);
    }

    std::vector<std::vector<int>> root(N);

    for (int i = 0; i < N; ++i)
        root[findfather(points[i])].push_back(i);

    for (int i = 0; i < N; ++i) {
        if (root[i].empty())
            continue;
        else {
            int len = root[i].size();
            for (int j = 0; j < len; ++j) {
                if (j != len - 1)
                    std::cout << root[i][j] << " ";
                else
                    std::cout << root[i][j] << std::endl;
            }
        }
    }

    return 0;  
}