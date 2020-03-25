//图的数组（邻接矩阵）表示法

#include <iostream>

#define INFINITY INT_MAX //最大值为无穷
#define MAX_VERTEX_NUM 20 //最大顶点个数
typedef enum {DG, DN, UDG, UDN} GraphKind; //{有向图，有向网，无向图，无向网}
typedef struct ArcCell
{
    int adj; //VRType是顶点关系类型。对无权图，用1或0表示相邻否；
    			//对带权图，则为权值类型
    char *info; //该弧相关信息的指针
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
    char vexs[MAX_VERTEX_NUM]; //顶点向量
    AdjMatrix arcs;  //邻接矩阵
    int vexnum, arcnum; //图的当前顶点数和弧数
    GraphKind kind; //图的种类标志
}MGraph;

void CreateUDN (MGraph &G); //采用邻接矩阵表示一个带权值的无向网

int main ()
{
    MGraph G;
    G.kind = UDN;
    CreateUDN(G);

    std::cout << "vexnum = " << G.vexnum << "; arcnum = " << G.arcnum << "; Graphkind: " << G.kind << std::endl;
    for (int i = 0; i < G.vexnum; i++) //输出各个顶点信息
        std::cout << G.vexs[i] << " ";
    std::cout << std::endl << std::endl;;
    for (int i = 0; i < G.vexnum; i++)  //输出邻接矩阵
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            if (G.arcs[i][j].adj == INT_MAX)
                std::cout << "m ";   //为无穷时输出m，为了美观
            else
                std::cout << G.arcs[i][j].adj << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;

    system("pause");
    return 0;
}

void CreateUDN (MGraph &G)  //假设弧不包含其他信息，即info为空
{
    std::cout << "Enter the vexnum and arcnum:";
    std::cin >> G.vexnum >> G.arcnum;
    std::cout << "Enter vexs:";
    for (int i = 0; i < G.vexnum; ++i)
        std::cin >> G.vexs[i]; //构造顶点向量
    for (int i = 0; i < G.vexnum; ++i)  //初始化邻接矩阵
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