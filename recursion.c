//
// Created by xiangming.fang on 2023/3/8.
//
#include "stdio.h"
#include <stdarg.h>


// 递归实现 1- n的累计和
int getsum(int n){
    if(n == 0) return 0;
    return n + getsum(n - 1);
}

double average(int num,...)
{

    va_list valist;
    double sum = 0.0;
    int i;

    /* 为 num 个参数初始化 valist */
    va_start(valist, num);

    /* 访问所有赋给 valist 的参数 */
    for (i = 0; i < num; i++)
    {
        sum += va_arg(valist, int);
    }
    /* 清理为 valist 保留的内存 */
    va_end(valist);

    return sum/num;
}

int main(){
    int count = 100;
    while (count --){
        printf("count(%d) 的累计和是 == %d\n",count, getsum(count));
    }

    // 可变参数
//    常用的宏有：
//
//    va_start(ap, last_arg)：初始化可变参数列表。ap 是一个 va_list 类型的变量，last_arg 是最后一个固定参数的名称（也就是可变参数列表之前的参数）。该宏将 ap 指向可变参数列表中的第一个参数。
//
//    va_arg(ap, type)：获取可变参数列表中的下一个参数。ap 是一个 va_list 类型的变量，type 是下一个参数的类型。该宏返回类型为 type 的值，并将 ap 指向下一个参数。
//
//    va_end(ap)：结束可变参数列表的访问。ap 是一个 va_list 类型的变量。该宏将 ap 置为 NULL。

    printf("1-10的平均数是：%f\n", average(10,1,2,3,4,5,6,7,8,9,10));


    return 0;
}