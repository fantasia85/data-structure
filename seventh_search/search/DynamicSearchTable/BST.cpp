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