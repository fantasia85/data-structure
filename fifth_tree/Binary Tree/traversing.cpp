//对表达式构成的二叉树，分别先序遍历（前缀表示（波兰式））、中序遍历（中缀表示）和后序遍历（逆波兰表达式）

#include <iostream>
#include <vector>
#include <stack>

/* //二叉树的数据结构
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
*/

struct TreeNode
{
    char val;
    TreeNode *left;
    TreeNode *right;
}; //用来存储表达式

void CreatTree (TreeNode *&node); //构造一棵二叉树

void PreorderTraverse (TreeNode *node, std::vector<char> &preorderT); //递归，先序遍历

void PreorderTraverse (TreeNode *root); //非递归,先序遍历

void InorderTraverse (TreeNode *node, std::vector<char> &inorderT); //递归，中序遍历

void InorderTraverse (TreeNode *root); //非递归，中序遍历

void PostorderTraverse (TreeNode *node, std::vector<char> &postorderT); //递归，后序遍历

void PostorderTraverse (TreeNode *root); //非递归，后序遍历

int main ()
{
    TreeNode *root = NULL;
    std::cout << "Binary Tree:" << std::endl;
    CreatTree(root); //输入为:-+a  *b  -c  d  /e  f  enter(ctrl+z)

    //先序遍历
    //递归，若只是为了输出，实际可以不用传递数组
    std::cout << "PreorderTraverse:" << std::endl;
    std::vector<char> preorderT;
    PreorderTraverse(root, preorderT);
    for (char c : preorderT)
        std::cout << c;
    std::cout << std::endl;
    //非递归
    PreorderTraverse(root);
    std::cout << std::endl << std::endl;


    //中序遍历
    std::cout << "InorderTraverse:" << std::endl;
    //递归，若只是为了输出，实际可以不用传递数组
    std::vector<char> inorderT;
    InorderTraverse(root, inorderT);
    for (char c : inorderT)
        std::cout << c;
    std::cout << std::endl;
    //非递归
    InorderTraverse(root);
    std::cout << std::endl << std::endl;

    //后序遍历
    std::cout << "PostorderTraverse:" << std::endl;
    //递归，若只是为了输出，实际可以不用传递数组
    std::vector<char> postorderT;
    PostorderTraverse(root, postorderT);
    for (char c : postorderT)
        std::cout << c;
    std::cout << std::endl;
    //非递归
    PostorderTraverse(root);
    std::cout << std::endl << std::endl;


    system ("pause");
    return 0;
}

void CreatTree (TreeNode *&node)
{
    char c;
    if (std::cin.get(c)) 
    {
        if (c == ' ')
            node = NULL;
        else
        {
            node = (TreeNode *) malloc (sizeof(TreeNode));
            node->val = c;
            CreatTree(node->left);
            CreatTree(node->right);
        }
    }
}

void PreorderTraverse (TreeNode *node, std::vector<char> &preorderT)
{
    if (!node)
        return;
    
    preorderT.push_back(node->val);
    PreorderTraverse (node->left, preorderT);
    PreorderTraverse (node->right, preorderT);
}

void PreorderTraverse (TreeNode *root)
{
    std::stack<TreeNode *> s1;
    if (!root)
        return;
    s1.push(root);
    while (!s1.empty())
    {
        TreeNode *temp = s1.top();
        s1.pop();
        std::cout << temp->val;
        if (temp->right)
            s1.push(temp->right);
        if (temp->left)
            s1.push(temp->left);
    }
}

void InorderTraverse (TreeNode *node, std::vector<char> &inorderT)
{
    if (!node)
        return;

    InorderTraverse (node->left, inorderT);
    inorderT.push_back(node->val);
    InorderTraverse (node->right, inorderT);
}

void InorderTraverse (TreeNode *root)
{
    if (!root)
        return;

    std::stack<TreeNode *> s2;
    s2.push(root);
    while (!s2.empty())
    {
        TreeNode *temp = s2.top();
        while (temp)
        {
            s2.push(temp->left);
            temp = temp->left;
        }  
        s2.pop();
        if (!s2.empty())
        {
            temp = s2.top();
            std::cout << temp->val;
            s2.pop();
            s2.push(temp->right);
        }
    }
}

void PostorderTraverse(TreeNode *node, std::vector<char> &postorderT)
{
    if (!node)
        return;

    PostorderTraverse(node->left, postorderT);
    PostorderTraverse(node->right, postorderT);
    postorderT.push_back(node->val);
}

void PostorderTraverse(TreeNode *root)
{
    std::stack<TreeNode *> s3;
    std::vector<char> res;
    TreeNode *cur = root, *pre = NULL;  //cur为当前指针，pre为前一个指针
    if (!root)
        return;
    while (cur || !s3.empty())
    {
        while (cur)
        {
            s3.push(cur);
            cur = cur->left;
        }
        cur = s3.top();
        if (!cur->right || cur->right == pre)
        {
            res.push_back(cur->val);
            s3.pop();
            pre = cur;
            cur = NULL;
        }
        else
        {
            cur = cur->right;
        }
    }
    for (char c : res)
        std::cout << c;
}