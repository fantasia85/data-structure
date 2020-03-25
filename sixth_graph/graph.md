### 6.图

***

* **图**（Graph）是一种较线性表和树更为复杂的数据结构。在线性表中，数据元素之间仅有线性关系，每个数据元素只有一个直接前驱和一个直接后继；在树形结构中，数据元素之间有着明显的层次关系，并且每一层上的数据元素可能和下一层中多个元素（即其孩子结点）相关，但只能和上一层中一个元素（即双亲结点）相关；而在图形结构中，结点之间的关系可以是任意的，图中任意两个数据元素之间都可能相关。
* 图的抽象数据类型：

```C++
//图的抽象数据类型
ADT Graph
{
    数据对象：
    数据关系：
    基本操作：
        CreateGraph(&G, V, VR);
    	DestroyGraph(&G);
    	LocateVex(G, u);
    	GetVex(G, v);
    	PutVex(&G, v, value);
    	FirstAdjVex(G, v);
    	NextAdjVex(G, v, w);
    	InsertVex(&G, v);
    	DeleteVex(&G, v);
    	InsertArc(&G, v, w);
    	DeleteArc(&G, v, w);
    	DFSTraverse(G, visit());
    	BFSTraverse(G, visit());
}ADT Graph
```

* 在图中的数据元素通常称为**顶点（Vectex）**，V是顶点的有穷非空集合，VR是两个顶点之间的关系的集合。
* 若<v,w>∈VR，则<v,w>表示从v到w的一条**弧（Arc）**，且称v为**弧尾（Tail）**或初始点（Initial node），称w为**弧头（Head）**或终端点（Terminal node），此时的图称为**有向图（Diagraph）**。
* 若<v,w>∈VR，必有<w,v>∈VR，即VR是对称的，则以无序对(v,w)代替这两个有序对，表示v和w之间的一条**边（Edge）**，此时的图称为**无向图（Undiagraph）**。
* 有向图*G1=（V1,{A1}）*，其中*V1={v1,v2,v3,v4}*，*A1={<v1,v2>,<v1,v3>,<v3,v4>,<v4,v1>}*。
* 无向图*G2=(V2,{E2})*，其中*V2={v1,v2,v3,v4,v5}*，*E2={(v1,v2),(v1,v4),(v2,v3),(v2,v5),(v3,v4),(v3,v5)}*。
* 有*1/2n(n-1)*条边的无向图称为**完全图（Completed graph）**。
* 有*n(n-1)*条弧的有向图称为**完全有向图**。
* 有很少条边或弧的图称为**稀疏图（Sparse graph）**，反之称为**稠密图（Dense graph）**。
* 有时图的边或弧具有与它相关的数，这种与图的边或弧相关的数叫做**权（Weight）**。这些权可以表示从一个顶点到另一个顶点的距离或耗费。这种带权的图通常称为**网（Network）**。
* 对于无向图*G=(V,{E})*，如果边*(v,v')∈E*，则称顶点v和v'互为**邻接点（Adjacent）**，即v和v'相邻接。
* 边(v,v')**依附（Incident）**于顶点v和v'，或者说(v,v')和顶点v和v‘**相关联**。
* 顶点v的**度（degree）**是和v相关联的边的数目，记为TD(v)。
* 对于有向图*G=(V,{A})*，如果弧*<v,v'>∈A*，则称顶点v邻接**到**顶点v'，顶点v'邻接**自**顶点v。
* 以顶点v为头的弧的数目称为v的**入度（InDegree）**，记为*ID(v)*；以v为尾的弧的数目称为v的**出度（OutDegree）**，记为*OD(v)*，顶点v的度为*TD(v)=ID(v)+OD(v)*。
* 路径的长度是路径上的边或弧的数目。
* 第一个顶点和最后一个顶点相同的路径称为**回路**或**环**（Cycle）。
* 序列中顶点不重复出现的路径称为**简单路径**。
* 如果对于图中任意两个顶点都是连通的，则称G是**连通图**（Connected Graph）。
* **连通分量（Connected Component）**是指无向图中的极大连通子图。
* 在有向图G中，如果对于每一对顶点*（vi,vj）*，从vj到vi和从vi到vj都存在路径，则称G是**强连通图**，有向图中的极大强连通子图称做有向图的**强连通分量**。



#### 图的存储结构

***

* 常用的存储结构有邻接表、邻接多重表和十字链表。

* 1. 数组表示法：用两个数组分别存储数据元素（顶点）的信息和数据元素之间的关系（边或弧）的信息。

  ```C++
  //图的数组（邻接矩阵）存储表示
  #define INFINITY INT_MAX //最大值为无穷
  #define MAX_VERTEX_NUM 20 //最大顶点个数
  typedef enum {DG, DN, UDG, UDN} GraphKind; //{有向图，有向网，无向图，无相网}
  typedef struct ArcCell
  {
      VRType adj; //VRType是顶点关系类型。对无权图，用1或0表示相邻否；
      			//对带权图，则为权值类型
      InfoType *info; //该弧相关信息的指针
  }ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
  typedef struct
  {
      VertexType vexs[MAX_VERTEX_NUM]; //顶点向量
      AdjMatrix arcs;  //邻接矩阵
      int vexnum, arcnum; //图的当前顶点数和弧数
      GraphKind kind; //图的种类标志
  }MGraph;
  ```

  