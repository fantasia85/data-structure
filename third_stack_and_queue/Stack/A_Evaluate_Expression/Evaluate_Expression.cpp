//表达式求值，以#结尾
//直接用库stack

#include <iostream>
#include <stack>
#include <cctype>

char signcompare (char s1, char s2); //运算符之间的优先级关系

int operator_s (int n1, int n2, char s); //执行相应的运算

int main()
{
    std::stack<int> OPND;
    std::stack<char> OPTR;
    OPTR.push('#'); //先将‘#’压入栈中
    int num = 0; //用来存储数字
    char c;
    bool n = false;
    c = std::cin.get();
    while (c != '#' || OPTR.top() != '#')
    {
        if (isdigit(c))
        {
            num = num * 10 + c - '0';
            n = true;
            c = std::cin.get();
        }
        else
        {
            if (n)
            {
                OPND.push(num);
                num = 0;
                n = false;
            }
            int temp1, temp2;
            char s;
            switch (signcompare(OPTR.top(), c))
            {
                case '<':
                    OPTR.push(c);
                    c = std::cin.get();
                    break;
                case '=':
                    OPTR.pop();
                    c = std::cin.get();
                    break;
                case '>':
                    temp2 = OPND.top(); OPND.pop();
                    temp1 = OPND.top(); OPND.pop();
                    s = OPTR.top(); OPTR.pop();
                    OPND.push(operator_s(temp1, temp2, s));
                    //OPTR.push(c);
                    break;
            }
            
        } 
    }
    std::cout << "Result: " << OPND.top() << std::endl;

    system ("pause");
    return 0;
}

char signcompare (char s1, char s2) //不考虑输入有错误的情况
{
    if (s1 == '(' && s2 == ')' || s1 == '#' && s2 == '#')
        return '=';
    else if (s1 == '(' && s2 != ')' || s1 == '#' && s2 != '#')
        return '<';
    else if (s2 == '(' && s1 != ')')
        return '<';
    else if ((s1 == '+' || s1 == '-') && (s2 == '*' || s2 == '/'))
        return '<';
    else
        return '>';
}

int operator_s(int n1, int n2, char s)
{
    int result;
    switch (s)
    {
        case '+': result = n1 + n2; break;
        case '-': result = n1 - n2; break;
        case '*': result = n1 * n2; break;
        case '/': result = n1 / n2; break;
        default: std::cout << "Error" << std::endl; break;
    }
    return result;
}