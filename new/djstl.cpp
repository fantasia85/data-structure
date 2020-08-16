//迪杰斯特拉算法
/* 
    样例输入
    4 5
    0 1 15
    1 2 15
    0 3 30
    2 3 10
    1 3 40
    3

    样例输出
    30
*/

#include <iostream>
#include <vector>

//图的每条边，这里用邻接矩阵存储
std::vector<std::vector<int>> graph;
//最短路径的前驱
std::vector<int> prev;
//到顶点的最短路径
std::vector<int> dist;
//当前节点是否已经加入集合中
std::vector<bool> points;

int target;

int main()
{
    int N, P;
    std::cin >> N >> P;

    //之间没有路径的距离，设置为无穷大，这里用2000代替
    graph = std::vector<std::vector<int>> (N, std::vector<int> (N, 2000));
    int x, y, T;
    for (int i = 0; i < P; ++i) {
        std::cin >> x >> y >> T;
        graph[x][y] = T;
    }

    std::cin >> target;

    points = std::vector<bool> (N, false);
    points[0] = true;

    prev = std::vector<int> (N, 0);
    prev[0] = -1;

    dist = std::vector<int> (N, 0);
    for (int i = 1; i < N; ++i)
        dist[i] = graph[0][i];
    
    //上一个新加入集合中的点，每次更新节点的值时，实际
    //只需要把当前的路径值和通过上一个新加入的点到源点
    //的值比较就好了.
    int last = 0;

    while (!points[target]) {
        int min = 2000;
        int pos = -1;
        //每次选一条到源点路径最短的点加入
        for (int i = 1; i < N; ++i) {
            //如果已经加入集合中，直接下一步
            if (points[i])
                continue;
            else {
                //更新节点到源点的值
                if (dist[last] + graph[last][i] < dist[i]) {
                    dist[i] = dist[last] + graph[last][i];
                    prev[i] = last;
                }
                //找到未加入节点中与源点距离最小的点
                if (dist[i] < min) {
                    min = dist[i];
                    pos = i;
                }
            }
        }
        last = pos;
        points[last] = true;
    }

    std::cout << dist[target] << std::endl;

    return 0;    
}