//2阶斐波那契数列与n阶汉诺塔
//Fabonacci and Hanoi

#include <iostream>

int fabonacci_n(int n); //2阶斐波那契数列

void hanoi_n (int n, char x, char y, char z); //n阶汉诺塔

void move (char x, int n, char y); //移动函数，用于输出移动的过程

int count = 0;

int main ()
{
    int n, result;
    char x = 'x', y = 'y', z = 'z';
    std::cout << "Enter n: ";
    std::cin >> n;

    result = fabonacci_n(n);
    std::cout << "fabonacci_n: " << result << std::endl << std::endl; 

    std::cout << n << " hanoi:" << std::endl;
    hanoi_n(n, x, y, z);
    std::cout << std::endl;

    system ("pause");
    return 0;
}

int fabonacci_n(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        return fabonacci_n(n - 1) + fabonacci_n(n - 2);
    }
}

void hanoi_n(int n, char x, char y, char z)
{
    if (n == 1)
        move(x, 1, z); //将编号为1的圆盘从x移到z
    else
    {
        hanoi_n(n - 1, x, z, y); //将x上编号为1至n-1的圆盘移动到y,z作辅助塔
        move(x, n, z);           //将编号为n的圆盘从x移到z
        hanoi_n(n - 1, y, x, z); //将y上编号为1至n-1的圆盘移到z,x作辅助塔
    }
}

void move (char x, int n, char z)
{
    std::cout << ++count << ". Move disk " << n << " from " << x << " to " << z << std::endl;
}