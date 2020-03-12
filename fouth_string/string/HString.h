#ifndef _HSTRING_H
#define _HSTRING_H

#include <iostream>

class HString
{
    public:
        HString() { ch = NULL; length = 0; } //默认构造函数
        
        ~HString () { ClearString(); } //析构函数，销毁串

        char operator[] (int i) { return ch[i]; } 

        HString(HString &S) 
        { 
            length = S.StrLength();
            ch = (char *) malloc ((length + 1) * sizeof(char) );
            for (int i = 0; i < length; i++)
                *(ch + i) = S[i];
            *(ch + length) = '\0';
        } //拷贝构造函数

        HString& operator= (HString &S)
        {
            if (ch)
                free(ch);
            length = S.StrLength();
            ch = (char *)malloc((length + 1) * sizeof(char));
            for (int i = 0; i < length; i++)
                *(ch + i) = S[i];
            *(ch + length) = '\0';
            return *this;
        } //赋值运算符

        void StrAssign (char *chars); //生成一个其值等于chars的串

        void ClearString ()
        {
            if (ch)
                free(ch);
            ch = NULL;
            length = 0;
        } //将S置为空串

        void Displays(); //用来输出字符串

        void StrCopy (HString S) { *this = S; } //由串S复制得到串

        bool StrEmpty() { return length == 0; } //若串为空串，则返回true，否则返回false

        int StrLength () { return length; } //返回S的元素个数，称为串的长度

        bool SubString (HString &Sub, int pos, int len); //用Sub返回串S的第pos个字符起长度为len的子串

        int Index (HString T, int pos); //若主串中存在和串T值相同的子串，则返回它在主串中第pos个字符之后第一次出现的位置，否则函数值为-1

        void Replace (HString T, HString V); //用V替换主串中出现的所有与T相等的不重叠的子串

        bool StrInsert (int pos, HString T); //在串的第pos个字符之前插入串T
        
        bool StrDelete (int pos, int len); //删除第pos个字符起长度为len的子串

        friend void Concat(HString &T, HString S1, HString S2); //用T返回由S1和S2链接而成的新串

        friend int StrCompare (HString S, HString T); //若S>T，返回值>0；若S== T，返回值=0；若S<T，返回值<0

    private:
        char *ch;
        int length;
};

void HString::StrAssign(char *chars)
{
    if (ch)
    {
        free(ch);
        ch = NULL;
    }
    length = 0;
    for (int i = 0; chars[i] != '\0'; i++)
    {
        length++;    
    }
    if (length)
    {
        ch = (char *) malloc ((length + 1) * sizeof (char));
        for (int i = 0; i < length; i++)
            *(ch + i) = *(chars + i);
        *(ch + length) = '\0';
    }
}

bool HString::SubString(HString &Sub, int pos, int len)
{
    if (Sub.ch)
        free(Sub.ch);
    if (pos < 0 || pos >= length || len < 0 || pos + len > length)
        return false;
    if (!len)
    {
        Sub.ch = NULL;
        Sub.length = 0;
    }
    else
    {
        Sub.ch = (char *) malloc ((len + 1) * sizeof (char));
        for (int i = 0; i < len; i++)
            *(Sub.ch + i) = * (ch + pos + i);
        Sub.length = len;
        *(Sub.ch + len) = '\0';
    }
    return true;
}

int HString::Index(HString T, int pos) //仅采用最简单的匹配算法
{
    int count = 0;
    if (pos < 0 || pos >= length || pos + T.length > length)
        return -1;
    if (!T.length)
        return pos;
    for (int i = pos; i < length; i++)
    {
        if (*(ch + i) == *(T.ch + count))
        {
            count++;
            if (count == T.length)
                return i - T.length + 1;
        }
        else
        {
            i = i - count;
            count = 0;
        }
        if (i + T.length - count >= length)
            return -1;
    }
    return -1;
}

bool HString::StrInsert(int pos, HString T)
{
    if (pos < 0 || pos > length + 1) //可插入位置为第0个字符到第最后一个字符的下一个字符之前
        return false;
    char *temp = (char *) malloc ((length + T.length + 1) * sizeof (char));
    for (int i = 0; i < pos; i++)
        *(temp + i) = *(ch + i);
    for (int i = 0; i < T.length; i++)
        *(temp + pos + i) = *(T.ch + i);
    for (int i = pos; i < length; i++)
        *(temp + T.length + i) = *(ch + i);
    *(temp + length + T.length) = '\0';
    length += T.length;
    free (ch);
    ch = temp;
    free (T.ch);
    T.ch = NULL;
    T.length = 0;
    return true;
}

bool HString::StrDelete(int pos, int len)
{
    if (pos < 0 || pos + len > length)
        return false;
    char *temp = (char *) malloc ((length - len + 1) *sizeof (char));
    for (int i = 0; i < pos; i++)
        *(temp + i) = *(ch + i);
    for (int i = pos + len; i < length; i++)
        *(temp + i - len) = *(ch + i);
    *(temp + length - len) = '\0';
    ch = temp;
    length -= len;  
    return true;
}

void HString::Displays()
{
    for (int i = 0; i < length; i++)
        std::cout << ch[i];
    std::cout << std::endl;
}

void HString::Replace(HString T, HString V)
{
    int pos = 0;
    while ((pos = Index(T, pos)) != -1)
    {
        StrDelete(pos, T.length);
        StrInsert(pos, V);
        pos += V.length;
    }
}

void Concat(HString &T, HString S1, HString S2)
{
    int tlength = S1.length + S2.length;
    char *temp = (char *) malloc ((tlength + 1) * sizeof (char));
    for (int i = 0; i < S1.length; i++)
        *(temp + i) = *(S1.ch + i);
    for (int i = 0; i < S2.length; i++)
        *(temp + S1.length + i) = *(S2.ch + i);
    *(temp + tlength) = '\0';
    T.length = tlength;
    T.ch = temp;
}

int StrCompare(HString S, HString T)
{
    for (int i = 0; S[i] != '\0' && T[i] != '\0'; i++)
    {
        if (S[i] > T[i])
            return 1;
        else if (S[i] < T[i])
            return -1;
    }
    if (S.length == T.length)
        return 0;
    return S.length > T.length ? 1 : -1;
}

#endif