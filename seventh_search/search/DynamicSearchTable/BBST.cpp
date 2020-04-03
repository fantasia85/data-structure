//平衡二叉树（Balanced Binary Tree）的插入和删除

#include <iostream>
#include <stack>  //用于输出当前平衡二叉树上现有的值

#define LH 1 //左高
#define EH 0 //等高
#define RH -1 //右高

struct BBST
{
    int val;
    int bf;  //结点的平衡因子
    BBST *left, *right;  //左、右孩子指针
    BBST()
    {
        val = 0;
        bf = EH;
        left = right = NULL;
    } //默认构造函数
    BBST(int n)
    {
        val = n;
        bf = EH;
        left = right = NULL;
    } //构造函数
};

bool InsertAVL(BBST *&T, int e, bool &taller);
//若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入一个数据元素为e的新结点，并返回true，否则返回false。
//若因插入而使二叉排序树失去平衡，则作平衡旋转处理，布尔变量taller反应T长高与否

void LeftBalance(BBST *&T);
//对以指针T所指结点为根的二叉树作左平衡旋转处理，本算法结束时，指针T指向新的根结点

void RightBalance(BBST *&T);
//对以指针T所指结点为根的二叉树作右平衡旋转处理，本算法结束时，指针T指向新的根结点

void R_Rotate(BBST *&T);
//对以*p为根的二叉排序树做右旋处理，处理之后p指向新的树根结点，即旋转处理之前的左子树的根结点

void L_Rotate(BBST *&T);
//对以*p为根的二叉排序树做左旋处理，处理之后p指向新的树根结点，及旋转处理之前的右子树的根结点

int main()
{
    BBST *T = NULL;
    int length;
    std::cout << "Enter length: ";
    std::cin >> length;
    int num;
    bool taller = false;
    std::cout << "Enter num to insert: ";
    for (int i = 0; i < length; i++)
    {
        std::cin >> num;
        InsertAVL(T, num, taller);
    }

    std::cout << "The num in AVL Tree: ";
    std::stack<BBST *> st1;
    if (!T)
        std::cout << "No num!";
    else
    {
        st1.push(T);
        while (!st1.empty())
        {
            BBST *node = st1.top();
            while (node)
            {
                st1.push(node->left);
                node = node->left;
            }
            st1.pop();
            if (!st1.empty())
            {
                node = st1.top();
                std::cout << node->val << " ";
                st1.pop();
                st1.push(node->right);
            }
        }
        std::cout << std::endl;
    }

    system("pause");
    return 0;
}

bool InsertAVL(BBST *&T, int e, bool &taller)
{
    if (!T)  //插入新结点，树“长高”，置taller为true
    {
        T = new BBST(e);
        taller = true;
    }
    else
    {
        if (T->val == e)   //树中已存在和e有相同关键字的结点，不再插入，返回false
        {
            taller = false;
            return false;
        }
        if (T->val > e)  //e的值比当前值小，继续在*T的左子树中进行搜索
        {
            if (!InsertAVL(T->left, e, taller))  //未插入结点，返回false
                return false;
            if (taller)  //插入到*T的左子树，且左子树增高
            {
                switch (T->bf)  //检查*T的平衡度
                {
                    case LH:  //原本左子树比右子树高，需要做左平衡处理
                        LeftBalance(T);
                        taller = false;
                        break;
                    case EH:  //原本左右子树等高，先因左子树增高而使树增高
                        T->bf = LH;
                        taller = true;
                        break;
                    case RH:  //原本右子树比左子树高，现左右子树等高
                        T->bf = EH;
                        taller = false;
                        break;
                }
            }
        }
        else  //应该继续在*T的右子树中进行搜索
        {
            if (!InsertAVL(T->right, e, taller))  //未插入结点，返回false
                return false;
            if (taller)   //插入到*T的右子树，且右子树增高
            {
                switch (T->bf)   //检查*T的平衡度
                {
                    case LH:  //原本左子树比右子树高，现左右子树等高
                        T->bf = EH;
                        taller = false;
                        break;
                    case EH:  //原本左右子树等高，先右子树增高而使树增高
                        T->bf = RH;
                        taller = true;
                        break;
                    case RH:  //原本右子树比左子树高，需要作右平衡处理
                        RightBalance(T);
                        taller = false;
                        break;
                }
            }
        }
    }
    return true;
}

void LeftBalance(BBST *&T)
{
    BBST *lc = T->left;  //lc指向*T的左子树根结点
    switch (lc->bf) //检查*T的左子树的平衡度，并作相应平衡处理 
    {
        case LH: //新结点插入在*T的左孩子的左子树上，做单右旋处理
            T->bf = lc->bf = EH; //旋转后均为EH
            R_Rotate(T);
            break;
        case RH: //新结点插入在*T的左孩子的右子树上，要做双旋处理
            BBST *rd = lc->right; //rd指向*T的左孩子的右子树根
            switch (rd->bf)  //修改*T及其左孩子的平衡因子
            {
                case LH:
                    T->bf = RH;
                    lc->bf = EH;
                    break;
                case EH:
                    T->bf = lc->bf = EH;
                    break;
                case RH:
                    T->bf = EH;
                    lc->bf = LH;
                    break;
            }
            rd->bf = EH;
            L_Rotate(T->left);  //对*T的左子树作左旋平衡处理
            R_Rotate(T); //对*T做右旋平衡处理
    }
}

void RightBalance(BBST *&T)
{
    BBST *rc = T->right; //lc指向*T的右子树根结点
    switch (rc->bf)     //检查*T的右子树的平衡度，并作相应平衡处理
    {
        case RH:                 //新结点插入在*T的右孩子的右子树上，做单左旋处理
            T->bf = rc->bf = EH; //旋转后均为EH
            L_Rotate(T);
            break;
        case LH:                  //新结点插入在*T的右孩子的左子树上，要做双旋处理
            BBST *ld = rc->left; //rd指向*T的右孩子的左子树根
            switch (ld->bf)       //修改*T及其右孩子的平衡因子
            {
                case LH:
                    T->bf = EH;
                    rc->bf = RH;
                    break;
                case EH:
                    T->bf = rc->bf = EH;
                    break;
                case RH:
                    T->bf = LH;
                    rc->bf = EH;
                    break;
            }
            ld->bf = EH;
            R_Rotate(T->right); //对*T的右子树作右旋平衡处理
            L_Rotate(T);       //对*T做左旋平衡处理
    }
}

void R_Rotate(BBST *&p)
{
    BBST *lc = p->left;  //lc指向*p的左子树的根结点
    p->left = lc->right;  //lc的右子树接为*p的左子树
    lc->right = p;
    p = lc;  //p指向新的根结点
}

void L_Rotate(BBST *&p)
{
    BBST *rc = p->right; //rc指向*p的右子树根结点
    p->right = rc->left; //rc的左子树挂接为*p的右子树
    rc->left = p;
    p = rc; //p指向新的根结点
}