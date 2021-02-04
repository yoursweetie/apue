##  C数据类型
> 
> #### 基本类型
> ##### 数值类型
> 1. 整形
> * short
> * int
> * long
>
> 2. 浮点型
> * float
> * double
> 
> * 字符类型 char
> 
> #### 构造类型
> * 数组
> * 结构体    struct
> * 共用体    union
> * 枚举类型    enum
> 
> #### 指针类型
> 
> #### 空类型  void
> 
> #### 布尔型 bool
> * true    (1)
> * false   (0)
> 
> **浮点型在计算机内的存储形式**
> 例如当浮点型的长度为32位(从0开始到31),其最高位表示正负,低23位表示小数部分,中间8位表示整数部分
> 需要注意的是,浮点型变量是一个大概的值,计算机不太可能完全精确地表示出数学上的浮点数,所以当我们要判断一个浮点变量的值是否等于0,我们可以这么判断:
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool judge_float(float f)
{
   if (fabs(f) <= 1e-6)
   {
        return true;
   }
   else
        return false;
}

int main()
{
    float x = 0.1;
    float y = 0.0000001;
    fprintf(stdout, "%f ~= 0 ?  %d\n", x, judge_float(x));
    fprintf(stdout, "%f ~= 0 ?  %d\n", y, judge_float(y));

    exit(0);
}
```

> **常量**
> > * 整型常量: 1, 2, 3...
> > * 实型常量: 3.14, 1.5, ...
> > * 字符常量: 由单引号引起来的一个字符或转义字符,如'a', 'X', '\n', '\t', ...
> > * 字符串常量: 由双引号引起来的一个或多个字符组成的序列,"a", "abcXY", "abc\n\021\018",""(空串), 字符串常量最后有一个转义字符'\0',即NULL字符, 来表示字符串的结束.尤其要注意的是,字符串常量放置在.rodata section中,所以不能对其修改,否则会segmentation fault.
> > * 标识符常量: #define BUFFSIZE 1024
> 
> 
> **变量**
> > 定义: [存储类型]  数据类型  标识符  =  值
> >       auto        int       a       =  1;
> >       register
> >       static
> >       extern
> > 
> > 可省略的存储类型分为:
> > * auto: 默认的选项,变量地址放在栈上.
> > * register: 放在寄存器中, 但只是建议性的,编译器不一定遵循,因为寄存器资源十分宝贵,必须满足苛刻的条件,编译器才会遵循.
> > * static(静态类型): 变量被放在.data section上, 即数据段上,数据段上存放的是初始化后的全局变量和局部静态变量(如static int a = 1;),如果static修饰的变量未初始化,自动初始化为0.
> > * extern(说明型, 上面3种都是定义型): 说明型,意味着不能改变被说明的变量的值或类型.
> ```c
> #include <stdio.h>
> #include <stdlib.h>
> 
> void func(void)
> {
>     static int x = 0;
>     x = x + 1;
>     fprintf(stdout; "static = %d\n"; x);
> }
> 
> int main()
> {
>     for(int i = 0; i < 3; i++)
>     {
>         func();
>     }
> 
>     exit(0);
> }
> ```
> 上面这段程序运行结果:
> ```
> static = 1
> static = 2
> static = 3
> ```
> ***static修饰的变量x,不论在哪里,一旦被定义过了,那么x就一直在被操作,它在内存中的地址也一直不变,因为它是在数据段中,不是在堆栈段.***

## 全局变量的缺点
来看这样一个程序:
```c
#include <stdio.h>
#include <stdlib.h>

int i = 0;

void func(void)
{
    for(int i = 0; i < 5; i++)
    {
        fprintf(stdout, "*");
        fprintf(stdout, "in %s, i = %d\n", __FUNCTION__, i);
    }
}
int main()
{
    for(i = 0; i < 5; i++)
    {
        func();
        fprintf(stdout, "in %s, i = %d\n", __FUNCTION__, i);
    }

    exit(0);
}
```

## 多文件编译
> #### main.c:
> ```c
> #include <stdio.h>
> #include <stdlib.h>
> #include "example.h"
> 
> //int i = 1;
> 
> int
> main()
> {
>     //fprintf(stdout, "[%s]: i = %d\n", __FUNCTION__, i);
>     fprintf(stdout, "hello from main\n");
>     func();
> 
>     exit(0);
> }
> ```
> #### example.c:
> ```c
> #include <stdio.h>
> #include <stdlib.h>
> 
> //int i = 1;
> 
> void
> func(void)
> {
>     //fprintf(stdout, "[%s]: i = %d\n", __FUNCTION__, i);
>     fprintf(stdout, "hello from example.c\n");
> 
>     exit(0);
> }
> ```
> #### example.h:
> ```c
> #ifndef EXAMPLE_H__
> #define EXAMPLE_H__
> 
> void func(void);
> 
> #endif
> ```
> #### gcc main.c example.c -E预处理之后结果比较长,就不放上来了,但是大概结构就是:
> ```c
> #include <stdio.h>
> #include <stdlib.h>
> 
> void func(void);
> 
> int
> main()
> {
>     fprintf(stdout, "hello from main\n");
>     func();
> 
>     exit(0);
> }
> 
> void func(void)
> {
> 
>     fprintf(stdout, "hello from example.c\n");
> 
>     exit(0);
> }
> ```
> ###### 可以看到,与我们把整个小项目一起写是一样的,出现头文件这个技术原因,大概是为了让分工合作更加方便.
