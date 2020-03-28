//广度优先遍历，BFS，在图的数组（邻接矩阵）表示法的基础上进行操作，无向图
//部分代码重叠

#include <iostream>
#include <vector>
#include <queue>

#define INFINITY INT_MAX  //最大值为无穷
#define MAX_VERTEX_NUM 20 //最大顶点个数
typedef enum
{
    DG,
    DN,
    UDG,
    UDN
} GraphKind; //{有向图，有向网，无向图，无向网}
typedef struct ArcCell
{
    int adj;    //VRType是顶点关系类型。对无权图，用1或0表示相邻否；
                //对带权图，则为权值类型
    char *info; //该弧相关信息的指针
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
    char vexs[MAX_VERTEX_NUM]; //顶点向量
    AdjMatrix arcs;            //邻接矩阵
    int vexnum, arcnum;        //图的当前顶点数和弧数
    GraphKind kind;            //图的种类标志
} MGraph;

void CreateUDN(MGraph &G); //采用邻接矩阵表示一个带权值的无向网

void BFSTraverse(const MGraph &G, std::vector<bool> &visited); //对图G做深度优先遍历

int FirstAdjVex(const MGraph &G, int v); //求第v个顶点的第一个邻接点，没有时返回-1

int NextAdjVex(const MGraph &G, int v, int w); //求第v个顶点在顶点w之后的下一个邻接点，没有时返回-1

int main()
{
    MGraph G;
    G.kind = UDN;
    CreateUDN(G);

    std::vector<bool> visited(G.vexnum, false); //访问标志数组并初始化
    std::cout << std::endl << "BFSTraverse_adjmatrix: " << std::endl;
    BFSTraverse(G, visited);
    std::cout << std::endl << std::endl;

    system("pause");
    return 0;
}

void CreateUDN(MGraph &G) //假设弧不包含其他信息，即info为空
{
    std::cout << "Enter the vexnum and arcnum:";
    std::cin >> G.vexnum >> G.arcnum;
    std::cout << "Enter vexs:";
    for (int i = 0; i < G.vexnum; ++i)
        std::cin >> G.vexs[i];         //构造顶点向量
    for (int i = 0; i < G.vexnum; ++i) //初始化邻接矩阵
        for (int j = 0; j < G.arcnum; ++j)
            G.arcs[i][j] = {INFINITY, NULL};
    for (int k = 0; k < G.arcnum; ++k) //构造邻接矩阵
    {
        char v1, v2;
        int w;
        std::cout << "Enter v1, v2 and w:";
        std::cin >> v1 >> v2 >> w; //输入一条边依附的顶点及权值
        int i1, j1;
        for (int i = 0; i < G.vexnum; ++i) //确定v1和v2在G中的位置
        {
            if (G.vexs[i] == v1)
                i1 = i;
            if (G.vexs[i] == v2)
                j1 = i;
        }
        G.arcs[i1][j1].adj = G.arcs[j1][i1].adj = w; //弧<v1,v2>和<v2,v1>的权值
    }
}

int FirstAdjVex(const MGraph &G, int v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.arcs[v][i].adj != INFINITY) //不为无穷大，表示有权值
            return i;
    }
    return -1;
}

int NextAdjVex(const MGraph &G, int v, int w)
{
    for (int i = w + 1; i < G.vexnum; i++)
    {
        if (G.arcs[v][i].adj != INFINITY) //不为无穷大，表示有权值
            return i;
    }
    return -1;
}

void BFSTraverse(const MGraph &G, std::vector<bool> &visited)
{
    std::queue<int> q1; //辅助队列q1
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            std::cout << G.vexs[i] << " ";
            q1.push(i);
        }
        while (!q1.empty())
        {
            int temp = q1.front();
            q1.pop();
            for (int w = FirstAdjVex(G, temp); w >= 0; w = NextAdjVex(G, temp, w))
            {
                if (!visited[w])
                {
                    visited[w] = true;
                    std::cout << G.vexs[w] << " ";
                    q1.push(w);
                }
            }
        }
    }
}
