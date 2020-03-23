//赫夫曼树和赫夫曼编码

#include <iostream>
#include <cstring>

//赫夫曼树和赫夫曼编码的存储表示
struct hfmtree
{
    unsigned int weight;
    unsigned int parent, lchild, rchild;
};  //动态分配数组存储赫夫曼树
typedef char ** hfmcode; //动态分配数组存储赫夫曼编码表

//w存放n个字符的权值(>0)，构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC
void hfmcoding (hfmtree *&HT, hfmcode &HC, int *w, int n);

//在HT[0..i-1]个树中选择parent为0且weight最小的两个结点，序号分别为s1和s2
void selete (hfmtree *&HT, int n, int &s1, int &s2);

int main ()
{
    hfmtree *HT;
    hfmcode HC;
    int w[] = {5, 29, 7, 8, 14, 23, 3, 11};
    int n = 8;
    hfmcoding (HT, HC, w, n);

    for (int i = 0; i < n; i++)
        std::cout << *(HC + i) << std::endl;

    system ("pause");
    return 0;
}

void hfmcoding (hfmtree *&HT, hfmcode &HC, int *w, int n)
{
    if (n <= 1)
        return;
    int m = 2 * n - 1;
    HT = new hfmtree[m];
    hfmtree *h = HT;
    int i = 0;
    while (i < n)  //初始化数组的前n个数值
    {
        h->weight = *w;
        h->parent = h->lchild = h->rchild = 0;
        h++;
        w++;
        i++;
    }
    while (i < m)  //初始化数组的后m-n个字符
    {
        h->weight = h->parent = h->lchild = h->rchild = 0;
        h++;
        i++;
    }
    //建立赫夫曼树
    int s1, s2;
    for (i = n; i < m; i++)
    {
        selete (HT, i, s1, s2);
        HT[s1].parent = HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }

    //从叶子到根逆向求每个字符的赫夫曼编码
    HC = new char *[n];  //分配n个字符编码的头指针向量
    char *cd = new char[n]; //分配求编码的工作空间
    cd[n - 1] = '\0';  //编码结束符
    for (int i = 0; i < n; i++)  //逐个字符求赫夫曼编码
    { 
        int start = n - 1;  //编码结束符位置
        int c = i;
        unsigned int f = HT[i].parent;
        while (f != 0)  //从叶子到根逆向求编码
        {
            if (HT[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
            c = f;
            f = HT[c].parent;
            HC[i] = new char[n - start];  //为第i个字符编码分配空间
            strcpy (HC[i], &cd[start]);   //从cd复制编码到HC
        }
    }
    delete [] cd;
}

void selete (hfmtree *&HT, int n, int &s1, int &s2)
{
    for (int i = 0; i < n; i++) //初始化s1,parent必须为0
    {
        if (!HT[i].parent)
        {
            s1 = i;
            break;
        }
    }
    for (int i = s1 + 1; i < n; i++) //初始化s2,parent必须为0
    {
        if (!HT[i].parent)
        {
            s2 = i;
            break;
        }
    }
    if (HT[s1].weight > HT[s2].weight) //找出s1和s2中较小的一个
    {
        int temp = s1;
        s1 = s2;
        s2 = temp;
    }
    for (int i = s1 + 1; i < n; i++)
    {
        if (HT[i].parent)
            continue;
        else
        {
            if (HT[i].weight < HT[s1].weight)
            {
                s2 = s1;
                s1 = i;
            }
            else if (HT[i].weight < HT[s2].weight)
                s2 = i;
        }
    }
}