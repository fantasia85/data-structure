#include "polynomial.h"
#include <iostream>

int main ()
{
    polynomial pn1;
    std::cout << pn1.PolynEmpty() << " " << pn1.PolynLength() << std::endl;
    pn1.PrintPolyn();

    int m;
    std::cout << "Input m:";
    std::cin >> m;
    pn1.CreatPolyn(m);
    std::cout << pn1.PolynEmpty() << " " << pn1.PolynLength() << std::endl;
    pn1.PrintPolyn();   //测试结果： 输入：
                        //Input m:5
                        //1. coef expn:1 2
                        //2. coef expn:6 3
                        //3. coef expn:2 2
                        //4. coef expn:-3 2
                        //5. coef expn:-5 5
                        //输出：
                        //0 2
                        //f(x) = 6x^3-5x^5

    polynomial pn2;
    int n;
    std::cout << "Input n:";
    std::cin >> n;
    pn2.CreatPolyn(n);
    std::cout << pn2.PolynEmpty() << " " << pn2.PolynLength() << std::endl;
    pn2.PrintPolyn();

    std::cout << "subtract:" << std::endl;
    pn1.SubtractPolyn(pn2);
    std::cout << pn1.PolynEmpty() << " " << pn1.PolynLength() << std::endl;
    pn1.PrintPolyn();
    std::cout << pn2.PolynEmpty() << " " << pn2.PolynLength() << std::endl;
    pn2.PrintPolyn();

    std::cout << "Input n:";
    std::cin >> n;
    pn2.CreatPolyn(n);
    std::cout << "add:" << std::endl;
    pn1.AddPolyn(pn2);
    std::cout << pn1.PolynEmpty() << " " << pn1.PolynLength() << std::endl;
    pn1.PrintPolyn();
    std::cout << pn2.PolynEmpty() << " " << pn2.PolynLength() << std::endl;
    pn2.PrintPolyn();

    std::cout << "Input n:";
    std::cin >> n;
    pn2.CreatPolyn(n);
    std::cout << "multiply:" << std::endl;
    pn1.MultiplyPolyn(pn2);
    std::cout << pn1.PolynEmpty() << " " << pn1.PolynLength() << std::endl;
    pn1.PrintPolyn();
    std::cout << pn2.PolynEmpty() << " " << pn2.PolynLength() << std::endl;
    pn2.PrintPolyn();

    std::cout << "clear:" << std::endl;
    pn1.DestroyPolyn();
    std::cout << pn1.PolynEmpty() << " " << pn1.PolynLength() << std::endl;
    pn1.PrintPolyn();

    system ("pause");
    return 0;
}