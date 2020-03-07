### 3.Stack and Queue
***
* 从数据结构角度看，栈和队列也是线性表，其特殊性在于栈和队列的基本操作是线性表操作的子集，它们是操作受限的线性表，因此，可称为限定性数据结构。但是从数据类型的角度看，它们是和线性表大不相同的两类重要的抽象数据类型。

#### Stack
***
* **栈（stack）** 是限定仅在表尾进行插入或删除操作的线性表。因此，对栈来说，表尾端有其特殊含义，称为**栈顶（top）** ，相应地，表头端称为**栈底（bottom）** 。不含元素的空表称为空栈。
* 栈又称为**后进先出（last in first out）** 的线性表（简称**LIFO** 结构）。
* 称插入元素的操作为入栈，删除栈顶元素的操作为出栈。
```
ADT Stack
{
  基本操作：
    InitStack(&S)
    DestroyStack(&S)
    ClearStack(&S)
    StackEmpty(S)
    StackLength(S)
    GetTop(S,&e)
    Push(&S,e)
    Pop(&S,&e)
    StackTraverse(S,visit())
}ADT Stack
```
* 栈的两种形式：顺序栈和链栈
  * [顺序栈SQStack](https://github.com/fantasia85/data-structure/tree/master/third_stack_and_queue/Stack/SQStack)
  
  * [链栈LLStack](https://github.com/fantasia85/data-structure/tree/master/third_stack_and_queue/Stack/LLStack)
  
* 栈的应用举例
  * [数制转换&括号匹配的检验&行编辑程序](https://github.com/fantasia85/data-structure/tree/master/third_stack_and_queue/Stack/Application)
  
  * [Leetcode_Valid_parentheses](https://leetcode.com/problems/valid-parentheses/)
  
  * 迷宫求解（暂无）
  
  * [表达式求值](https://github.com/fantasia85/data-structure/blob/master/third_stack_and_queue/Stack/A_Evaluate_Expression/Evaluate_Expression.cpp)

* 栈与递归的实现
  * [2阶斐波那契数列（Fibonacci）](https://github.com/fantasia85/data-structure/blob/master/third_stack_and_queue/Stack/Stack_and_recursion/Fibonacci_and_hanoi.cpp)
  ```
  FIb(n) = 0 若n = 0
           1 若n = 1
           Fib(n-1) + Fib(n-2)
  ```
  * [n阶汉诺塔（Hanoi）](https://github.com/fantasia85/data-structure/blob/master/third_stack_and_queue/Stack/Stack_and_recursion/Fibonacci_and_hanoi.cpp)
  ```c++
  void hanoi (int n, char x, char y, char z)
  {
  	if (n == 1)
  		move (x, 1, z); //将编号为1的圆盘从x移到z
  	else
  	{
  		hanoi(n - 1, x, y, z); //将x上编号为1至n-1的圆盘移动到y,z作辅助塔
  		move(x, n, z); //将编号为n的圆盘从x移到z
  		hanoi(n-1, y, x, z); //将y上编号为1至n-1的圆盘移到z,x作辅助塔
  	}
  }
  ```

#### Queue
***
* 和栈相反，**队列（queue）** 是一种**先进先出（first in first out，缩写为FIFO）** 的线性表。它只允许在表的一端进行插入操作，而在另一端删除元素。

* 在队列中，允许插入的一端叫做**队尾（rear）** ，允许删除的一端则称为**队头（front）** 。

  ```
  ADT Queue
  {
  	数据对象：
  	数据关系：
  	基本操作：
  		InitQueue(&Q)
  		DestroyQueue(&Q)
  		ClearQueue(&Q)
  		QueueEmpty(Q)
  		QueueLength(Q)
  		GetHead(Q,&e)
  		EnQueue(&Q,e)
  		DeQueue(&Q,&e)
  		QueueTraverse(Q,visit())
  }ADT Queue
  ```
  
* 除了栈和队列之外，还有一种限定性数据结构是**双端队列（deque）** 。

* 用链表表示的队列简称为[链队列](https://github.com/fantasia85/data-structure/tree/master/third_stack_and_queue/Queue/LLQueue)。

* 将顺序队列臆造为一个环状的空间，称为**循环队列** 。

  * 只凭等式Q.front = Q.rear无法判断队列空间是“空”还是“满”。可有两种处理方法：其一是另设一个标志位以区别队列是“空“还是”满“；其二是少用一个元素空间，约定以“队列头指针在队列尾指针的下一位置（指环状的下一位置）上”作为队列呈“满”状态的标志。
  
    
  
  
