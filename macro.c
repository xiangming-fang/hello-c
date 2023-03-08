//
// Created by xiangming.fang on 2023/3/8.
//

#include "stdio.h"
#include <errno.h>
#include <string.h>

//ANSI C 定义了许多宏。在编程中您可以使用这些宏，但是不能直接修改这些预定义的宏。

//#define	定义宏
//#include	包含一个源代码文件
//#undef	取消已定义的宏
//#ifdef	如果宏已经定义，则返回真
//#ifndef	如果宏没有定义，则返回真
//#if	如果给定条件为真，则编译下面代码
//#else	#if 的替代方案
//#elif	如果前面的 #if 给定条件不为真，当前条件为真，则编译下面代码
//#endif	结束一个 #if……#else 条件编译块
//#error	当遇到标准错误时，输出错误消息
//#pragma	使用标准化方法，向编译器发布特殊的命令到编译器中

extern int errno ;

int main()
{
    printf("File :%s\n", __FILE__ );
    printf("Date :%s\n", __DATE__ );
    printf("Time :%s\n", __TIME__ );
    printf("Line :%d\n", __LINE__ );
    printf("ANSI :%d\n", __STDC__ );

//    C 语言提供了 perror() 和 strerror() 函数来显示与 errno 相关的文本消息。
//
//    perror() 函数显示您传给它的字符串，后跟一个冒号、一个空格和当前 errno 值的文本表示形式。
//    strerror() 函数，返回一个指针，指针指向当前 errno 值的文本表示形式。


    FILE * pf;
    int errnum;
    pf = fopen ("unexist.txt", "rb");
    if (pf == NULL)
    {
        errnum = errno;
        fprintf(stderr, "错误号: %d\n", errno);
        perror("通过 perror 输出错误");
        fprintf(stderr, "打开文件错误: %s\n", strerror( errnum ));
    }
    else
    {
        fclose (pf);
    }
    return 0;

}