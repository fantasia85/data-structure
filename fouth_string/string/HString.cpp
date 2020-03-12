//按照自己的HString.h进行操作

#include <iostream>
#include "HString.h"

int main()
{
    char *cs = "Hello!";
    HString s1, s2;
    s2.StrAssign(cs);
    std::cout << s1.StrEmpty() << " " << s1.StrLength() << std::endl;
    s1.Displays();
    std::cout << s2.StrEmpty() << " " << s2.StrLength() << std::endl;
    s2.Displays();
    std::cout << std::endl;

    s1.StrCopy(s2);
    std::cout << s1.StrEmpty() << " " << s1.StrLength() << std::endl;
    s1.Displays();
    std::cout << std::endl;

    s1.ClearString();
    std::cout << s1.StrEmpty() << " " << s1.StrLength() << std::endl;
    s1.Displays();
    std::cout << std::endl;
    s1.StrCopy(s2);

    s1.SubString(s2, 1, 2);
    std::cout << s1.StrEmpty() << " " << s1.StrLength() << std::endl;
    s1.Displays();
    std::cout << s2.StrEmpty() << " " << s2.StrLength() << std::endl;
    s2.Displays();
    std::cout << std::endl;

    int pos = s1.Index(s2, 0);
    std::cout << pos << std::endl;
    pos = s1.Index(s2, 2);
    std::cout << pos << std::endl;
    std::cout << std::endl;

    char *cs1 = "elHelloHelloHElloELelhel"; 
    s1.StrAssign(cs1);
    char *cs2 = "WWW";
    HString s3;
    s3.StrAssign(cs2);
    s1.Replace(s2, s3);
    std::cout << s1.StrEmpty() << " " << s1.StrLength() << std::endl;
    s1.Displays();
    std::cout << std::endl; //StrInsert和StrDelete已包含在replace中，不再重复测试

    Concat (s3, s1, s2);
    std::cout << s3.StrEmpty() << " " << s3.StrLength() << std::endl;
    s3.Displays();
    std::cout << std::endl;

    std::cout << StrCompare (s3, s1) << std::endl;
    std::cout << StrCompare(s1, s3) << std::endl;
    std::cout << StrCompare(s3, s2) << std::endl;
    std::cout << StrCompare(s2, s3) << std::endl;
    std::cout << std::endl;

    Concat (s1, s1, s2);
    std::cout << s3.StrEmpty() << " " << s3.StrLength() << std::endl;
    s3.Displays();
    std::cout << StrCompare(s3, s1) << std::endl;
    std::cout << StrCompare(s1, s3) << std::endl;
    std::cout << std::endl;

    system ("pause");
    return 0;
}