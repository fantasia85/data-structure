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

* 1. [数组表示法](https://github.com/fantasia85/data-structure/blob/master/sixth_graph/graph/adjmatrix.cpp)：用两个数组分别存储数据元素（顶点）的信息和数据元素之间的关系（边或弧）的信息。

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

* 2. 邻接表（Adjacency List）：是图的一种链式存储结构。在邻接表中，对图中每个顶点建立一个单链表，第i个单链表中的结点表示依附于顶点vi的边（对有向图是以顶点vi为尾的弧）。

  * 每个结点由3个域组成，其中邻接点域（adjvex）指示与顶点vi邻接的点在图中的位置，链域（nextarc）指示下一条边或弧的结点；数据域（info）存储和边或弧相关的信息，如权值等。
  * 每个链表上附设一个表头结点。

  ```C++
  //图的邻接表存储表示
  #define MAX_VERTEX_NUM 20
  typedef struct ArcNode
  {
      int adjvex; //该弧所指示的顶点的位置
      struct ArcNode *nextarc; //指示下一条弧的指针
      InfoType *info; //该弧相关信息的指针
  }ArcNode;
  typedef strucct VNode
  {
      VertexType data; //顶点信息
      ArcNode *firstarc; //指示第一条依附该顶点的弧的指针
  }VNode, AdjList[MAX_VERTEX_NUM];
  typedef struct
  {
      AdjList vertices; 
      int vexnum, arcnum; //图的当前顶点数和弧数
      int kind; //图的种类标志
  }ALGraph;
  ```

  * 在无向图的邻接表中，顶点vi的度恰为第i个链表中的结点数；而在有向图中，第i个链表中的结点个数只是顶点vi的出度，为求入度，必须遍历整个邻接表。

* 3. [十字链表（Orthogonal List）](https://github.com/fantasia85/data-structure/blob/master/sixth_graph/graph/orthogonal_list.cpp)是有向图的另一种链式存储结构。可以看成是将有向图邻接表和逆邻接表结合起来得到的一种链表。

  * 在弧结点中有5个域：其中尾域（tailvex）和头域（headvex）分别指示弧尾和弧头这两个顶点在图中的位置，链域hlink指示弧头相同的下一条弧，而链域tlink指示弧尾相同的下一条弧，info域指向该弧的相关信息。
  * 弧头相同的弧在同一链表上，弧尾相同的弧也在同一链表上。
  * 它们的头结点即为顶点结点，它由3个域组成：其中data域存储和顶点相关的信息，如顶点的名称等，firstin和firstout为两个链域，分别指向以该顶点为弧头或弧尾的第一个弧结点。

  ```C++
  //有向图的十字链表存储表示
  #define MAX_VERTEX_NUM 20
  typedef struct ArcBox
  {
      int tailvex, headvex; //该弧的尾和头顶点的位置
      struct ArcBox *hlink, *tlink; //分别为弧头相同和弧尾相同的弧的链域
      InfoType *info; //该弧相关信息的指针
  }ArcBox;
  typedef struct VexNode
  {
      VertexType data;
      ArcBox *firstin, *firstout; //分别指向该顶点第一条入弧和出弧
  }VexNode;
  typedef struct
  {
      VexNode xlist[MAX_VERTEX_NUM]; //表头向量
      int vexnum, arcnum; //有向图的当前顶点数和弧数
  }OLGraph;
  ```

* 4. 邻接多重表（Adjacency Multilist）是无向图的另一种链式存储结构。

  * 邻接多重表的结构和十字链表类似。
  * 在邻接多重表中，每一条边用一个结点表示，它由6个域组成：mark为标志域，可用以标记该条边是否被搜索过；ivex和jvex为该边依附的两个顶点在图中的位置；ilink指向下一条依附于顶点ivex的边；jlink指向下一条依附于顶点jvex的边，info为指向和边相关的各种信息的指针域。
  * 每一个顶点也用一个结点表示，它由2个域组成：data域存储和该顶点相关的信息，firstedge域指示第一条依附于该顶点的边。

  ```c++
  //无向图的邻接多重表存储表示
  #define MAX_VERTEX_NUM 20
  typedef enum {unvisited, visited} VisitIf;
  typedef struct EBox
  {
      VisitIf mark; //访问标记
      int ivex, jvex; //该边依附的两个顶点的位置
      struct EBox *ilink, *jlink; //分别指向依附这两个顶点的下一条边
      InfoType *info; //该边信息指针
  }EBox;
  typedef struct VexBox
  {
      VertexType data;
      EBox *firstedge; //指向第一条依附该顶点的边
  }VexBox;
  typedef struct
  {
      VexBox adjmulist[MAX_VERTEX_NUM];
      int vexnum, edgenum; //无向图的当前顶点数和边数
  }AMLGraph;
  ```


#### 图的遍历

***

* 图的遍历（Traversing Graph）是指从图中某一顶点出发访遍图中其余结点，且使每一个顶点仅被访问一次。
* 通常有两条遍历图的路径：深度优先搜索和广度优先搜索，他们对无向图和有向图都适用。
* [**深度优先搜索**](https://github.com/fantasia85/data-structure/blob/master/sixth_graph/graph/DFSTraverse_adj.cpp)（Depth_first_search）遍历类似于树的先根遍历，是树的先根遍历的推广。
  * 假设初始状态是图中所有顶点未曾被访问，则深度优先搜索可以从图中某个顶点v出发，访问此顶点，然后依次从v的未被访问的邻接点出发深度优先遍历图，直至图中所有和v有路径相通的顶点都被访问到；若此时图中尚有顶点未被访问，则另选图中一个未曾被访问的顶点作起始点，重复上述过程，直至图中所有顶点都被访问到为止。
  * 为了在遍历过程中便于区分顶点是否已被访问，需附设访问标志数组visit[n]，其初值为"false"，一旦某个顶点被访问，则其相应的分量置为"true"。
* [**广度优先搜索**](https://github.com/fantasia85/data-structure/blob/master/sixth_graph/graph/BFSTraverse_adj.cpp)（Broadth_first_search）遍历类似于树的按层次遍历的过程。
  * 假设从图中某顶点v出发，在访问了v之后一次访问v的各个未曾访问过的邻接点，然后分别从这些邻接点出发依次访问他们的邻接点，并使“先被访问的顶点的邻接点”先于”后被访问的顶点的邻接点“被访问，直至图中所有已被访问的顶点的邻接点都被访问到。若此时图中尚有顶点未被访问，则另选图中一个未曾被访问的顶点作起始点，重复上述过程，直至图中所有顶点都被访问到为止。
  * 换句话说，广度优先搜索遍历图的过程是以v为起始点，由近至远，依次访问和v有路径相通且路径长度为1,2，...的顶点。
* 

