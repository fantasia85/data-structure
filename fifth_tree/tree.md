### 5. Tree

***

* 树型结构是一类重要的非线性数据结构，其中以树和二叉树最为常用，直观看来，树是以分支关系定义的层次结构。
* 树（Tree）是*n*个结点的有限集，在任意一棵非空树中：
  * 有且仅有一个特定的称为**根（Root）**的结点；
  * 当n>1时，其余结点可分为*m*个互不相交的有限集，其中每一个集合本身又是一棵树，并且称为根的**子树（Subtree）**。

```c++
ADT Tree
{
	数据对象：
	数据关系：
	基本操作：
		InitTree(&T)
		DestroyTree(&T)
		CreateTree(&T,definition)
		ClearTree(&T)
		TreeEmpty(T)
		TreeDepth(T)
		Root(T)
		Value(T, cur_e)
		Assign(T, cur_e, value)
		Parent(T, cur_e)
		LeftChild(T, cur_e)
		RightChild(T, cur_e)
		InsertChild(&T, &p, i, c)
		DeleteChild(&T, &p, i)
		TraverseTree(T, visit())
}ADT Tree
```

* 树结构中的基本术语
  * 树的**结点**包含一个数据元素及若干指向其子树的分支；
  * 结点拥有的子树数称为**结点的度（Degree）**；
  * 度为0的结点称为**叶子（Leaf）**或**终端结点**；
  * 度不为0的结点称为**非终端结点**或**分支结点**；
  * 除根结点之外，分支结点也称为内部结点，**树的度**是树内各结点的度的最大值；
  * 结点的子树的根称为该结点的**孩子（Child）**，相应地，该结点称为孩子的**双亲（Parent）**；
  * 同一个双亲的孩子之间互称**兄弟（Sibling）**；
  * 结点的**祖先**是从根到该结点所经分支上的所有节点；
  * 反之，以某结点为根的子树中的任一结点都称为该结点的**子孙**；
  * 结点的**层次（Level）**从根开始定义起，根为第一层，根的孩子为第二层；
  * 其双亲在同一层的结点互为**堂兄弟**；
  * 树中结点的最大层次称为树的**深度（Depth）**或高度；
  * 如果将树中结点的各子树看成从左至右是有次序的，则称该树为**有序树**，否则称为**无序树**，在有序树中最左边的子树的根称为第一个孩子，最右边的称为最后一个孩子。
* **森林（Forest）**是*m*棵互不相交的树的集合，对树中的每个结点而言，其子树的集合即为森林。

#### 二叉树

***

* **二叉树（Binary Tree）**是另一种树型结构，它的特点是每个结点至多只有两颗子树（即二叉树中不存在度大于2的结点），并且，二叉树的子树有左右之分，其次序不能任意颠倒。

```c++
ADT BinaryTree
{
	数据对象：
	数据关系：
	基本操作:
		InitBiTree(&T)
		DestroyBiTree(&T)
		CreateBiTree(&T, definition)
		ClearBiTree(&T)
		BiTreeEmpty(T)
		BiTreeDepth(T)
		Root(T)
		Value(T, e)
		Assign(T, &e, value)
		Parent(T, e)
		LeftChild(T, e)
		RightChild(T, e)
		LeftSibling(T, e)
		RightSibling(T, e)
		InsertChild(T, p, LR, c)
		DeleteChild(T, p, LR)
		PreOrderTraverse(T, Visit())
		InOrderTraverse(T, Visit())
		PostOrderTraverse(T, Visit())
		LevelOrderTraverse(T, Visit())
}ADT BinaryTree
```

* **二叉树的性质**

  1. 在二叉树的第*i*层上至多有*2^(i-1)*个结点(*i >= 1*)。

  2. 深度为*k*的二叉树至多有*2^(k-1)*个结点(*k>=1*)。

  3. 对任何一棵二叉树T，如果其终端结点树为*n0*，度为2的结点数为*n2*，则*n0=n2+1*。

* 一棵深度为*k*且有*2^(k-1)*个结点的二叉树称为**满二叉树**。

* 深度为*k*的，有*n*个结点的二叉树，当且仅当其每一个结点都与深度为*k*的满二叉树中编号从1至*n*的结点一一对应时，称之为**完全二叉树**。这种树的特点是：

  * 叶子结点只可能在层次最大的两层上出现；
  * 对任一结点，若其右分支下的子孙的最大层次为*l*，则其左分支下的子孙的最大层次必为*l*或*l+1*。

  4. 具有*n*个结点的完全二叉树的深度为*𠃊log2n𠃎+1*。

  5. 如果对一棵有*n*个结点的完全二叉树（其深度为*𠃊log2n𠃎+1*）的结点按层序编号（从第1层到第*𠃊log2n𠃎+1*层，每层从左到右），则对任一结点*i*（1<=*i*<=*n*），有

     * 如果*i*=1，则结点*i*是二叉树的根，无双亲；如果*i*>1，则其双亲PARENT(*i*)是结点*𠃊i/2𠃎*。
     * 如果*2i*>*n*，则结点*i*无左孩子（结点*i*为叶子结点）；否则其左孩子LCHILD(*i*)是结点2*i*。
     * 如果2*i*+1>*n*，则结点*i*无右孩子；否则其右孩子RCHILD(*i*)是结点2*i*+1。

* **二叉树的存储结构**

  * 顺序存储结构：

  ```c++
  //二叉树的顺序存储表示
  #define MX_TREE_SIZE 100
  typedef TElemType SqBiTree[MAX_TREE_SIZE];
  SqBiTree bt;
  ```

  * 链式存储结构：二叉树的链表中的结点至少包括3个域：数据域和左、右指针域。链表的头结点指向二叉树的根节点。

  ```c++
  //二叉树的二叉链表存储表示
  typedef struct BiTNode
  {
  	TElemType data;
  	struct BiTNode *lchild, *rchild; //左右孩子指针
  }BiTNode, *BiTree
  ```

* [**遍历二叉树**](https://github.com/fantasia85/data-structure/blob/master/fifth_tree/Binary%20Tree/traversing.cpp)

  * 先序遍历二叉树的操作定义为：

    若二叉树为空，则空操作；否则

    1.  访问根节点；
    2.  先序遍历左子树；
    3.  先序遍历右子树。

  * 中序遍历二叉树的操作定义为：

    若二叉树为空，则空操作，否则

    1. 中序遍历左子树；
    2.  访问根节点；
    3. 中序遍历右子树。

  * 后序遍历二叉树的操作定义为：

    若二叉树为空，则空操作；否则

    1. 后序遍历左子树；
    2. 后序遍历右子树；
    3.  访问根节点。

* 不论按哪一种次序进行遍历，对含*n*个结点的二叉树，其时间复杂度为*O(n)*。所需辅助空间为遍历过程中栈的最大容量，即树的深度，最坏情况下为*n*，则空间复杂度也为*O(n)*。

* 线索二叉树

  * 试做如下规定：若结点有左子树，则其lchild域指示其左孩子，否则令lchild域指示其前驱；若结点有右子树，则其rchild域指示其右孩子，否则令rchild域指示其后继。
  * 以这种结点结构构成的二叉链表作为二叉树的存储结构，叫做**线索链表**，其中指向结点前驱和后继的指针，叫做**线索**。加上线索的二叉树称之为**线索二叉树（Threaded Binary Tree）**。对二叉树以某种次序遍历使其变为线索二叉树的过程叫做**线索化**。
  * 在中序线索树中找结点后继的规律是：若其右标志为“1”，则右链为线索，指示其后继，否则遍历右子树时访问的第一个结点（右子树中最左下的结点）为其后继。
  * 在中序线索树中找结点前驱的规律是：若其左标志为“1”，则左链为线索，指示其前驱，否则遍历左子树时最后访问的一个结点（左子树中最右下的结点）为其前驱。

  ```c++
  //二叉树的二叉线索存储表示
  typedef enum PointerTag { Link, Thread }; //Link == 0:指针，Thread == 1:线索
  typedef struct BiThrNode 
  {
  	TElemType data;
  	struct BiThrNode *lchild, *rchild; //左右孩子指针
  	PointerTag LTag, TRTag; //左右标志
  }BiThrNode, *BiThrTree;
  ```

#### **树和森林**

***

* 树的存储结构

  1. 双亲表示法：以一组连续空间存储树的结点，同时在每个结点中附设一个指示器指示其双亲结点在链表中的位置。

  ```c++
  //树的双亲表存储表示
  #define MAX_TREE_SIZE 100
  typedef struct PTNode //结点结构
  {
  	TElemType data;
  	int parent; //双亲位置域
  }PTNode;
  typedef struct //树结构
  {
  	PTNode nodes[MAX_TREE_SIZE]；
  	int r,n; //根的位置和结点树
  }PTree;
  ```

  2. 孩子表示法：把每个结点的孩子结点排列起来，看成是一个线性表，且以单链表作为存储结构，则n个结点有n个孩子链表（叶子的孩子链表为空表）。而n个头指针又组成一个线性表，为了便于查找，可采用顺序存储结构。

  ```c++
  //树的孩子链表存储表示
  typedef struct CTNode //孩子结点
  {
  	int child;
  	struct CTNode *next;
  } *ChildPtr;
  typedef struct
  {
  	TElemType data;
  	ChildPtr firstchild; //孩子链表头指针
  }CTBox;
  typedef struct
  {
  	CTBox nodes[MAX_TREE_SIZE];
  	int n,r; //结点数和根的位置
  }CTree;
  ```

  3. 孩子兄弟表示法：又称二叉树表示法， 或二叉链表表示法。即以二叉链表作为树的存储结构。链表中结点的两个链域分别指示该结点的第一个孩子结点和下一个兄弟结点，分别命名为firstchild域和nextsibling域。

  ```c++
  //树的二叉链表（孩子-兄弟）存储表示
  typedef struct CSNode
  {
  	ElemType data;
  	struct CSNode *firstchild, *nextsibling;
  }CSNode, *CSTree;
  ```

* 森林与二叉树的转换：从树的二叉链表表示的定义可知，任何一棵和树对应的二叉树，其右子树必空。若把森林中第二棵树的根节点看成是第一棵树的根节点的兄弟，则同样可以导出森林和二叉树的对应关系。

* 有树结构的定义可以引出两种次数遍历树的方法：一种是先根（次序）遍历树，即先访问树的根结点，然后依次先根遍历根的每棵子树；另一种是后根（次序）遍历，即先依次后根遍历每棵子树，然后访问根结点。

* 森林的两种遍历方法：先序遍历森林和中序遍历森林。森林的先序和中序遍历即为其对应的二叉树的先序和中序遍历。

#### **赫夫曼（Huffman）树**

***



* 赫夫曼（Huffman）树，又称最优树，是一类带权路径长度最短的树。
* 从树中一个结点到另一个结点之间的分支构成这两个结点之间的路径，路径上的分支数目称做**路径长度**。
* **树的路径长度**是从树根到每一结点的路径长度之和。完全二叉树就是这种路径长度最短的二叉树。
* 结点的带权路径长度为从该结点到树根之间的路径长度与结点上权的乘积。**树的带权路径长度**为树中所有叶子结点的带权路径长度之和，通常记作*WPL*。
* 带权路径长度*WPL*最小的二叉树称做**最优二叉树**或**赫夫曼树**。

* 赫夫曼算法：
  1. 根据给定的*n*个权值{*w1*,*w2*,...,*wn*}构成*n*棵二叉树的集合F={*T1*,*T2*,...,*Tn*}，其中每棵二叉树*Ti*中只有一个带权为*wi*的根结点，其左右子树均空。
  2. 在F中选取两棵根节点的权值最小的树作为左右子树构造一棵新的二叉树，且置新的二叉树的根结点的权值为其左、右子树上根结点的权值之和。
  3. 在F中删除这两棵树，同时将新得到的二叉树加入F中。
  4. 重复2和3，直到F只含一棵树为止。这棵树便是赫夫曼树。
* [赫夫曼编码](https://github.com/fantasia85/data-structure/blob/master/fifth_tree/Huffman/huffman.cpp)：
  * 若要设计长短不等的编码，则必须是任一个字符的编码都不是另一个字符的编码的前缀，这种编码称做**前缀编码**。
  * 一棵有*n*个叶子结点的赫夫曼树共有*2n-1*个结点，可以存储在一个大小为*2n-1*的一维数组中。
  * 在构成赫夫曼树之后，为求编码需从叶子结点出发走一条从叶子到根的路径；而为译码需从根出发走一条从根到叶子的路径。

```c++
//赫夫曼树和赫夫曼编码的存储表示
typedef struct
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree; //动态分配数组存储赫夫曼树
typedef char **HuffmanCode; //动态分配数组存储赫夫曼编码表
```

#### 回溯（Backtracking）法与树的遍历

***

* 回溯法也是设计递归过程的一种重要方法，它的求解过程实际上是一个先序遍历一棵“状态树”的过程，只是这棵树不是遍历前预先建立的，而是隐含在遍历过程中。
* [求n个元素的集合的幂集](https://github.com/fantasia85/data-structure/blob/master/fifth_tree/Backtracking/powerset.cpp)
* [4(8)皇后问题](https://github.com/fantasia85/data-structure/blob/master/fifth_tree/Backtracking/queen_4.cpp)