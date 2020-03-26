//有向图的十字链表

#include <iostream>

//有向图的十字链表存储表示
#define MAX_VERTEX_NUM 20
typedef struct ArcBox
{
    int tailvex, headvex;         //该弧的尾和头顶点的位置
    struct ArcBox *hlink, *tlink; //分别为弧头相同和弧尾相同的弧的链域
    char *info;               //该弧相关信息的指针
} ArcBox;
typedef struct VexNode
{
    char data;
    ArcBox *firstin, *firstout; //分别指向该顶点第一条入弧和出弧
} VexNode;
typedef struct
{
    VexNode xlist[MAX_VERTEX_NUM]; //表头向量
    int vexnum, arcnum;            //有向图的当前顶点数和弧数
} OLGraph;

void CreateDG(OLGraph &G); //采用十字链表存储表示，构造有向图G（G.kind = DG）

int main()
{
    OLGraph G;
    CreateDG(G);
    std::cout << "vexnum: " << G.vexnum << "; arcnum: " << G.arcnum << std::endl;
    for (int i = 0; i < G.vexnum; i++)
    {
        std::cout << "data: " << G.xlist[i].data << std::endl <<  "ID: " << std::endl;
        ArcBox *inode = G.xlist[i].firstin;
        while (inode)
        {
            std::cout << G.xlist[inode->tailvex].data << "->" << G.xlist[inode->headvex].data << std::endl;
            inode = inode->hlink;
        }
        std::cout << std::endl << "OD: " << std::endl;
        ArcBox *onode = G.xlist[i].firstout;
        while (onode)
        {
            std::cout << G.xlist[onode->tailvex].data << "->" << G.xlist[onode->headvex].data << std::endl;
            onode = onode->tlink;
        }
        std::cout << std::endl << std::endl;
    }

    system ("pause");
    return 0;
}

void CreateDG(OLGraph &G)
{
    std::cout << "Enter vexnum and arcnum:"; //输入顶点数和弧数
    std::cin >> G.vexnum >> G.arcnum; 
    for (int i = 0; i < G.vexnum; ++i)   //构造表头向量
    {
        std::cout << "Enter xlist[" << i << "].data:";
        std::cin >> G.xlist[i].data;   //初始化顶点的值
        G.xlist[i].firstin = G.xlist[i].firstout = NULL; //初始化指针
    }
    char v1, v2;
    for (int j = 0; j < G.arcnum; ++j)   //输入各弧并构造十字链表
    {
        std::cout << "Enter v1 and v2:";
        std::cin >> v1 >> v2;  //输入一条弧的始点和终点
        int m, n;
        for (int i = 0; i < G.vexnum; ++i)   //确定v1和v2在G中的位置
        {
            if (v1 == G.xlist[i].data)
                m = i;
            if (v2 == G.xlist[i].data)
                n = i;
        }
        ArcBox *p = new ArcBox;  //构造结点
        *p = {m, n, G.xlist[n].firstin, G.xlist[m].firstout, NULL}; //对弧结点赋值{tailvex, headvex, hlink, tlink, info}
        G.xlist[n].firstin = G.xlist[m].firstout = p; //完成赋值后，每次在入弧和出弧的链头位置插入
    }
}
