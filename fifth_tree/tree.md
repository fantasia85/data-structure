### 5. Tree

***

* 树型结构是一类重要的非线性数据结构，其中以树和二叉树最为常用，直观看来，树是以分支关系定义的层次结构。
* 树（Tree）是*n*个结点的有限集，在任意一棵非空树中：
  * 有且仅有一个特定的称为**根（Root）**的结点；
  * 当n>1时，其余结点可分为*m*个互不相交的有限集，其中每一个集合本身又是一棵树，并且称为根的**子树（Subtree）**。

```
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

```
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

  ```
  //二叉树的顺序存储表示
  #define MX_TREE_SIZE 100
  typedef TElemType SqBiTree[MAX_TREE_SIZE];
  SqBiTree bt;
  ```

  * 链式存储结构：二叉树的链表中的结点至少包括3个域：数据域和左、右指针域。链表的头结点指向二叉树的根节点。

  ```
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

* 