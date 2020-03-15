#include <iostream>
#include <string>
#include <vector>

int Index (std::string &s1, std::string &s2, int pos);  //简单的模式匹配

int Index_KMP (std::string &s1, std::string &s2, int pos, std::vector<int> &next); //KMP算法模式匹配

//实际测试还存在部分问题
void get_next (std::string &s2, std::vector<int> &next);

void get_nextval (std::string &s2, std::vector<int> &next); //改进的get_next函数

int main()
{
    std::string s1, s2;
    int pos = 0;
    std::cout << "Enter s1 && s2:" << std::endl;
    std::cin >> s1 >> s2;
    
    std::cout << "Enter pos:";
    std::cin >> pos;

    int pos1 = Index (s1, s2, pos);
    std::cout << "pos1 = " << pos1 << std::endl;

    std::vector<int> next1(s2.length());
    get_next (s2, next1);
    int pos2 = Index_KMP(s1, s2, pos, next1);
    std::cout << "pos2 = " << pos2 << std::endl;

    std::vector<int> next2(s2.length());
    get_nextval(s2, next2);
    int pos3 = Index_KMP(s1, s2, pos, next2);
    std::cout << "pos3 = " << pos3 << std::endl;

    system ("pause");
    return 0;
}

int Index (std::string &s1, std::string &s2, int pos) //pos从0开始到s1.length-1。不存在返回-1
{
    if (pos < 0 || pos >= s1.length())
        return -1;
    int i = pos, j = 0;
    while (i < s1.length() && j < s2.length())
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= s2.length())
        return i - j;
    else 
        return -1;
}

int Index_KMP(std::string &s1, std::string &s2, int pos, std::vector<int> &next)
{
    if (pos < 0 || pos >= s1.length())
        return -1;
    int i = pos, j = 0;
    while (i < s1.length() && j < s2.length())
    {
        if (j == -1 || s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j >= s2.length())
        return i - j;
    else
        return -1;
}

void get_next(std::string &s2, std::vector<int> &next)
{
    next[0] = -1;
    int i = 0, j = -1;
    while (i < s2.length() - 1)
    {
        if (j == -1 || s2[i] == s2[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
        
    }

}

void get_nextval (std::string &s2, std::vector<int> &next)
{
    next[0] = -1;
    int i = 0, j = -1;
    while (i < s2.length() - 1)
    {
        if (j == -1 || s2[i] == s2[j])
        {
            i++;
            j++;
            if (s2[i] != s2[j])
                next[i] = j;
            else
            {
                next[i] = next[j];
            }
            
        }
        else
        {
            j = next[j];
        }
    }
}