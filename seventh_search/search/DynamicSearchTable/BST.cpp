//二叉排序树（Binary Search Tree）的插入和删除操作

#include <iostream>

struct BiST
{
    int val;
    BiST *left, *right;
    BiST() { val = 0; left = right = NULL; } //默认构造函数
    BiST(int n) { val = n; left = right = NULL; } //构造函数 
};

bool SearchBST(BiST *T, int key, BiST *f, BiST *&p); 
//在根指针T所指二叉排序树中递归地查找其关键字等于key的数据元素，若查找成功，则指针p指向该数据元素结点，并返回true；
//否则指针p指向查找路径上访问的最后一个结点并返回false，指针f指向T的双亲，其初始调用值为NULL

bool InsertBST(BiST *&T, int e);
//当二叉排序树T中不存在关键字等于e.key的数据元素时，插入e并返回true，否则返回false

bool DeleteBST(BiST *&T, int e);
//若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点，并返回true，否则返回false

bool Delete(BiST *&p);
//从二叉排序树中删除结点p，并重接它的左或右子树

int main()
{
    BiST *root = NULL;
    int length, num;
    std::cout << "Enter length: ";
    std::cin >> length;
    std::cout << "Enter num: ";
    for (int i = 0; i < length; i++)
    {
        std::cin >> num;
        InsertBST(root, num);
    } 

    BiST *p1 = NULL;
    int searchnum;
    std::cout << "Num to search: ";
    std::cin >> searchnum;
    if (SearchBST(root, searchnum, NULL, p1))
    {
        std::cout << "Found num, val = " << p1->val << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }
    std::cout << std::endl;

    int deletenum;
    std::cout << "Num to delete: ";
    std::cin >> deletenum;
    bool dlt = DeleteBST(root, deletenum);
    if (dlt)
        std::cout << "Delete " << deletenum << std::endl;
    else
        std::cout << "Not found " << deletenum << std::endl;
    
    system ("pause");
    return 0;
}

bool SearchBST(BiST *T, int key, BiST *f, BiST *&p)
{
    if (!T)
    {
        p = f;
        return false;
    }   //查找不成功，p指向其父亲结点，并返回false
    if (T->val == key)
    {
        p = T;
        return true;
    }  //查找成功，p指向该结点，并返回true
    else if (T->val > key)
    {
        return SearchBST(T->left, key, T, p);
    }  //关键字的值小于根结点的值，在左子树中继续查找
    else
    {
        return SearchBST(T->right, key, T, p);
    }  //关键字的值大于根结点的值，在右子树中继续查找
}

bool InsertBST(BiST *&T, int e)
{
    BiST *p = NULL;
    if (!SearchBST(T, e, NULL, p)) //查找不成功
    {
        BiST *node = new BiST(e);
        if (!p)
            T = node; //被插入结点*node为新的根结点
        else if (p->val > e)
            p->left = node;  //被插入结点为左孩子
        else
        {
            p->right = node; //被插入结点为右孩子
        }
        return true;
    }
    return false;
}

bool DeleteBST(BiST *&T, int e)
{
    if (!T)
        return false;  //不存在关键字等于e的数据元素
    else
    {
        if (T->val == e)  //找到关键字等于e的数据元素
            return Delete(T);
        else if (T->val > e)
            return DeleteBST(T->left, e);
        else
        {
            return DeleteBST(T->right, e);
        }
    }
}

bool Delete(BiST *&p)
{
    if (!p->right) //右子树为空，只需要重接它的左子树
    {
        BiST *q = p;
        p = p->left;
        delete q;
    }
    else if (!p->left) //左子树为空，只需要重接它的右子树
    {
        BiST *q = p;
        p = p->right;
        delete q;
    }
    else   //左右子树均不为空
    {
        BiST *q = p, *s = p->left;
        while (s->right)
        {
            q = s;
            s = s->right;
        }   //向左走，然后向右到尽头。s结点此时为p结点的直接前驱
        p->val = s->val;   
        if (q != p)
            q->right = s->left; //当直接前驱不为p的左孩子时，重接*q的右子树
        else
        {
            q->left = s->left; //当直接前驱为p的左孩子时，重接*q的左子树
        }
        delete s;
    }   
    return true;
}