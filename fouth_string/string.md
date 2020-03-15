### 4. String

***

* **串（string）**（或字符串）是由零个或多个字符组成的有限序列。串中字符的数目*n*称为串的**长度** 。零个字符的串称为**空串（null string）**，它的长度为零。
* 串中任意个连续的字符组成的子序列称为该串的**子串**。包含子串的串相应地称为**主串**。通常称字符在序列中的序号为该字符在串中的**位置**。子串在主串中的位置则以子串的第一个字符的主串中的位置来表示。
* 称两个串是**相等**的，当且仅当着这两个串的值相等。
* 由一个或多个空格组成的串‘ ’称为**空格串（blank string）**。它的长度为串中空格字符的个数。

```
ADT String
{
	数据对象：
	数据关系：
	基本操作：
		StrAssign (&T, chars)
		StrCopy (&T, S)
		StrEmpty (S)
		StrCompare (S, T)
		StrLength (S)
		ClearString (&S)
		Concat (&T, S1, S2)
		SubString (&Sub, S, pos, len)
		Index (S, T, pos)
		Replace (&S, T, V)
		StrInsert (&S, pos, T)
		StrDelete (&S, pos, len)
		DestroyString (&S)
} ADT String
```

* 串的三种表示方法：

  * 定长顺序存储表示

    串的实际长度可在这预定义长度的范围随意，超过预定义长度的串值则被舍去，称之为“截断”。
    
    在顺序存储结构中，实现串操作的原操作为“字符序列的复制“，操作的时间复杂度基于复制的字符序列的长度。

  ```
  //串的定长顺序存储表示
  #define  MAXSTRLEN 255 
  typedef  unsigned char SString[MAXSTRLEN + 1]
  ```

  * [堆分配存储表示](https://github.com/fantasia85/data-structure/tree/master/fouth_string/string)

    这种存储表示的特点是，仍以一组地址连续的存储单元存放串值字符序列，但它们的存储空间是在程序执行过程中动态分配而得。

    存在着一个称之为“堆”的自由存储区，并由动态分配函数malloc()和free()来管理。利用函数malloc()为每个新产生的串分配一块实际串长所需的存储空间，若分配成功，则返回一个指向起始地址的指针，作为串的基址，同时，为了以后处理方便，约定串长也作为存储结构的一部分。

  ```
  //串的堆分配存储表示
  typedef struct
  {
  	char *ch;
  	int length;
  }Hstring;
  ```

  * 串的块链存储表示

    用链表存储串值时，存在一个“结点大小”的问题，即每个结点可以存放一个字符，也可以存放多个字符。

    当以链表存储串值时，除头指针外还可附设一个尾指针指示链表中的最后一个结点，并给出当前串的长度，称如此定义的串存储结构为**块链结构**。

  ```
  //串的块链存储表示
  #define CHUNKSIZE 80
  typedef struct Chunk
  {
  	char ch[CHUNKSIZE];
  	struct Chunk *next;
  }Chunk;
  typedef struct
  {
  	Chunk *head, *tail; //串的头和尾指针
  	int curlen; //串的当前长度
  }LString;
  ```


#### **模式匹配**

***

* 子串的定位操作通常称做串的**模式匹配** （其中T称为**模式串** ），是各种串处理系统中的最重要的操作之一。
* 最简单的模式匹配：时间复杂度为*O(n+m)*，在最坏情况下的时间复杂度为*O(n*****m)*。
* 模式匹配的改进算法： [KMP算法](https://github.com/fantasia85/data-structure/blob/master/fouth_string/string/Index_match.cpp)，可以在*O(n+m)*的时间数量级上完成串的模式匹配操作。
  * 其改进在于：每当一趟匹配过程中出现字符比较不等时，不虚回溯i指针，而是利用已经得到的“部分匹配”的结果将模式向右“滑动”尽可能远的一段距离后，继续进行比较。
  * 若令*next[j] = k*，则*next(j)*表明当前模式中第j个字符与主串中相应字符“失配”时，在模式中需重新和主串中该字符进行比较的字符的位置。
  * 不同之处在于：当匹配过程中产生“失配”时，指针i不变，指针j退回到*next[j]*所指示的位置上重新进行比较，并且当指针j退至零时，指针i和指针j同时增1。即若主串的第i个字符和模式的第1个字符不等，应从主串的第j+1个字符起重新进行匹配。