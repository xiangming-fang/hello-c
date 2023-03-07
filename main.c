// 预处理器指令，告诉 C 编译器在实际编译之前要包含 stdio.h 文件
#include <stdio.h>
#include <float.h>
#include "string.h"

// 定义常量
//    在 C 中，有两种简单的定义常量的方式：

//    使用 #define 预处理器。
//    使用 const 关键字。

#define LENGTH 999999999
#define WIDTH 99999999
#define NEWLINE '\n'

int x = 1,y = 999999999;

int addtwonum();

// 全局变量，static是默认的
static char staticChar = 's';
static int count = 10;

void fun1()
{
    // static 修饰方法内的变量，每次调用这个方法并不会都执行 thingy的初始化，只有第一次会走
    // 对这个方法是 “静态” 的
    static int thingy = 5;
    thingy ++;
    printf("thingy === %d\n",thingy);
}

// 函数声明
void swap(int x,int y);

// 函数定义
// 传值调用，传入的入参将值复制给形参，所以形参的具体改变不关具体传值的参数
void swap(int x,int y)
{
    int temp = x;
    x = y;
    y = temp;
    // 形参确实交换了
    printf("形参 x == %d\n",x);
    printf("形参 y == %d\n",y);
}

// 引用调用
void referenceSwap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//数组名是一个指向数组中第一个元素的常量指针。
void array1(int *param,int size){

    while (size > 0){
        // 指针移动
        printf("%d ",*(param+(--size)));
    }
    printf("\n");
}

void array2(int param[],int size);
void array2(int param[],int size){
    // 不能直接通过数组获取这个数组的大小，所以需要额外传
    while (size > 0){
        int temp = param[--size];
        printf("%d  ",temp);
        if(size == 8) param[size] = 999;
    }
    printf("\n");
}

// 定义month这个枚举的类型
enum MONTH{
    january = 1,
    february = 2,
    march = 3,
    april = 4,
    may = 5,
    june = 6,
    july = 7,
    august = 8,
    september = 9,
    october = 10,
    november = 11,
    december = 12
};

enum MONTH month;


int max(int x,int y){
    return x > y ? x : y;
}

int maxThree(int x,int y,int z,int (*p)(int,int)){
    return (p(x,y),z);
}

struct SIMPLE
{
    int as;
    char bs;
    double cs;
};

// 打印simple 这个结构体变量的值
void printSimple(struct SIMPLE t){
    printf("%d %c %f\n",t.as,t.bs,t.cs);
}

struct
{
    // 用三位表示范围是：000 —— 111，十进制就是 0 - 7
    unsigned int age : 3;
} Age;



// 主函数，程序从这里开始执行
int main() {
    // hello world
    printf("Hello, World!\n");

//    %lu 为 32 位无符号整数
    printf("int 存储大小：%lu \n",sizeof(int));
    printf("double 存储大小：%lu \n",sizeof(double));
    printf("long double 存储大小：%lu \n",sizeof(long double));
    printf("float 存储大小：%lu \n",sizeof(float));
    printf("long 存储大小：%lu \n",sizeof(long));

//    %E 为以指数形式输出单、双精度实数
    printf("float 最小值：%E\n",FLT_MIN);

//    声明、不是定义
    extern int i;
//    声明、也是定义（需要建立存储空间的）
    int j;

    int result = addtwonum();

    printf("result 为：%d\n",result);

//    整数常量也可以带一个后缀，后缀是 U 和 L 的组合，U 表示无符号整数（unsigned），L 表示长整数（long）。后缀可以是大写，也可以是小写，U 和 L 的顺序任意。
    int num = 199999UL;
    printf("num = %d\n",num);


    // 字符串常量

    char string[] = "hello,hello-c";
    printf("字符串是 ==> %s\n",string);
    printf("字符串的第一个字符 ==> %hello-c\n",string[0]);


    // 预处理常量
    printf("area == %d",(LENGTH * WIDTH));
    printf("%hello-c",NEWLINE);

    // const 声明常量
    const int con = 666;
    printf("const value == %d%hello-c",con,NEWLINE);


    // 存储类
//    auto   所有局部变量默认的存储类，定义在函数中的局部变量默认是auto存储类，这意味着它们在函数开始时被创建，在函数结束时被销毁
//    register   用于定义存储在寄存器中而不是 RAM 中的局部变量。这意味着变量的最大尺寸等于寄存器的大小（通常是一个字），且不能对它应用一元的 '&' 运算符（因为它没有内存位置）。
//               存储类定义存储在寄存器，所以变量的访问速度更快，但是它不能直接取地址，因为它不是存储在 RAM 中的
//    static     指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁. 因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。
//               修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。
    while (count -- > 0){
        fun1();
    }

//    extern  用于定义在其他文件中声明的全局变量或函数，当使用 extern 关键字时，不会为变量分配任何存储空间，而只是指示编译器该变量在其他文件中定义。

    // 逻辑运算符，不为0就是真，是0就是假
    int logic = 9;
    int logic2 = 10;
    if(logic) {
        printf("非0为真\n");
    }
    if(!0){
        printf("0为假\n");
    }

    if(logic && logic2){
        printf("logic 并且 logic2都不为0\n");
    }

    if(logic && logic2 && !0){
        printf("我直接&&个0\n");
    }

    // 杂项运算符

    // 妈的，就是这块，以前大学搞了半天搞不懂，现在回头看，不难理解啊，哈哈，笑死。
    // logicAddress 包含 logic 的地址
    // *logicAddress 是 logicAddress这块地址里的值
    int* logicAddresss = &logic;
    printf("logic变量指向的内存地址是 == %d",logicAddresss);
    printf("logicAddresss 地址离存的值 == %d",*logicAddresss);

    if(*&logic == logic){
        printf("那必须相等啊，logic 变量指向的内存地址里面的值 == logic \n");
    }


//    注释掉以下代码，别卡主
//    int pleaseInputNum;
//
//    printf("请输入一个数：");
//    scanf("%d",&pleaseInputNum);
//    (pleaseInputNum & 1) == 0 ? printf("%d 是 偶数\n",pleaseInputNum) : printf("%d 是 奇数\n",pleaseInputNum);

//  传值调用：该方法把参数的实际值复制给函数的形式参数。在这种情况下，修改函数内的形式参数不会影响实际参数。
    int a = 100,b = 200;
    swap(a,b);
    // 传入的a,b只是复制了一份给x,y，所以a,b的值并没有变
    printf("a === %d\n",a);
    printf("b === %d\n",b);

//    通过指针传递方式，形参为指向实参地址的指针，当对形参的指向操作时，就相当于对实参本身进行的操作。
    printf("引用调用\n");
    referenceSwap(&a,&b);
    // 传入的a,b只是复制了一份给x,y，所以a,b的值并没有变
    printf("a === %d\n",a);
    printf("b === %d\n",b);

//    在程序中，局部变量和全局变量的名称可以相同，但是在函数内，如果两个名字相同
//    全局变量与局部变量在内存中的区别：
//    全局变量保存在内存的全局存储区中，占用静态的存储单元；
//    局部变量保存在栈中，只有在所在函数被调用时才动态地为变量分配存储单元。


//    数组
//    int balance[10]; // 声明数组
//    数组名是一个指向数组中第一个元素的常量指针。
    int nums[] = {100,2,3,4,5,6,7,8,9,10}; // 声明并初始化数组
    array1(nums,10);

    // 默认就是引用调用，改变了的值还会带出来
    array2(nums,10);

    printf("%d\n",nums[8]);

    // 使用枚举
    month = march;
    printf("几月份？ ==》 %d\n",month);

    // 将数值转成月份枚举
    enum MONTH month1 = (enum MONTH)1;
    printf("强转 ===》 %d\n",month1);


    // 指针：指针也就是内存地址。指针变量是用来存放内存地址的变量。就像其他变量或常量一样，您必须在使用指针存储其他变量地址之前，对其进行声明
    // 每一个变量都有一个内存位置，每一个内存位置都定义了可使用 & 运算符访问的地址，它表示了在内存中的一个地址。

    int    *ip;    /* 一个整型的指针 */
    double *dp;    /* 一个 double 型的指针 */
    float  *fp;    /* 一个浮点型的指针 */
    char   *ch;    /* 一个字符型的指针 */

    // 指针变量
    int* addr1 = &month;
    int *addr2 = &month;
//    addr1 和 addr2都是month变量的指向内存地址
// 指针addr2和addr1的类型必须和month一致，因为整型指针只能存储整型变量的内存地址
    printf("addr1 == %d   addr2 == %d\n",addr1,addr2);

    int *point = NULL;
    printf("空指针 point 的地址是 %p\n",point);


//    函数指针是指向函数的指针变量。
//
//    通常我们说的指针变量是指向一个整型、字符型或数组等变量，而函数指针是指向函数。
//
//    函数指针可以像一般函数一样，用于调用函数、传递参数。

//    函数指针, *p 一定要打括号
    int (*p)(int,int) = max;
    // 这用法是不是太变态了？？？我直接调用max() 不就好了吗？这不是相当于给方法名重命名吗？？？
    printf("3,4的最大值是 %d\n",p(3,4));

    // 函数指针作为某个函数的参数。 ==》 是真的秀啊，这种写法
    // 一个函数作为另一个函数的入参 six
    printf("回调函数测试：7，8，9 最大值 = %d\n",maxThree(7,8,9,p));

    char apple[] = {'a','p','p'};
    printf("%s\n",apple);
    printf("%d\n", strlen(apple));

    // 结构体
    // 结构体定义由关键字 struct 和结构体名组成，结构体名可以根据需要自行定义。
    struct Books{
        int ab;
        char bb;
        double cb;
    } book;

    //此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
    //结构体的标签被命名为SIMPLE,没有声明变量
    // 结构体就是java中的普通类呀

    struct SIMPLE t1,t2,t3;
    struct Books b1,b2[20],b3;
    for (int k = 0; k < 20; ++k) {
        // 都是默认值
        printf("%d %c %f\n",b2[k].ab,b2[k].bb,b2[k].cb);
    }

    // 结构体变量的定义初始化
    struct SIMPLE t = {1,'f',0.00009};
    printSimple(t);
    // 结构指针
    struct SIMPLE *sp = &t;
    // 结构指针获取对应结构对象里的属性值 用 ->
    printf("%d ",sp->as);

    // 共用体是一种特殊的数据类型，允许您在相同的内存位置存储不同的数据类型。 ==> 这又是什么骚操作，同一个内存地址存储不同的数据类型？？？
    // 为了定义共用体，您必须使用 union 语句，方式与定义结构类似。
    union Data
    {
        int i;
        float f;
        char  str[20];
    } data;
    // Data 类型的变量可以存储一个整数、一个浮点数，或者一个字符串。这意味着一个变量（相同的内存位置）可以存储多个多种类型的数据。
    // 你是真的秀，原来是这个意思……，既然这么说的话，应该里面的成员变量只能存在一个有值，多个的话就是结构体了呀，就不是共用体了???
    // 共用体占用的内存应足够存储共用体中最大的成员。例如，在上面的实例中，Data 将占用 20 个字节的内存空间，因为在各个成员中，字符串所占用的空间是最大的。下面的实例将显示上面的共用体占用的总内存大小：

    printf("Memory size occupied by data : %d\n", sizeof(data));
    data.i = 10;
    data.f = 220.5;
    strcpy(data.str,"java");
    printf( "data.i : %d\n", data.i);
    printf( "data.f : %f\n", data.f);
    printf( "data.str : %s\n", data.str);
    // 卧槽？？？你管这个叫共用体？我的老哥，你这个和结构体没区别呀。

    // 位域：如果您在结构内使用这样的变量，您可以定义变量的宽度来告诉编译器，您将只使用这些字节
    // 带有预定义宽度的变量被称为位域。
    struct bs{
        int a:8;
        int b:2;
        int c:6;
    } bitarea;
    // bitarea 为 bs 变量，共占两个字节。其中位域 a 占 8 位，位域 b 占 2 位，位域 c 占 6 位。

    Age.age = 4;
    printf( "Sizeof( Age ) : %d\n", sizeof(Age) );
    printf( "Age.age : %d\n", Age.age );

    Age.age = 7;
    printf( "Age.age : %d\n", Age.age );

    Age.age = 8; // 二进制表示为 1000 有四位，超出
    printf( "Age.age : %d\n", Age.age );


    // 在这个位域定义中，a 占第一字节的 4 位，后 4 位填 0 表示不使用，b 从第二字节开始，占用 4 位，c 占用 4 位。
    struct bbs{
        unsigned a:4;
        unsigned  :4;    /* 空域 */
        unsigned b:4;    /* 从下一单元开始存放 */
        unsigned c:4
    };

    // C 语言提供了 typedef 关键字，您可以使用它来为类型取一个新的名字。
    // 为无符号整型取一个 uint别名
    typedef unsigned int uint;

    uint aaa = 555;
    printf("%d\n",aaa);

//    typedef vs #define
//
//    #define 是 C 指令，用于为各种数据类型定义别名，与 typedef 类似，但是它们有以下几点不同：
//
//    typedef 仅限于为类型定义符号名称，#define 不仅可以为类型定义别名，也能为数值定义别名，比如您可以定义 1 为 ONE。
//    typedef 是由编译器执行解释的，#define 语句是由预编译器进行处理的。

// 输入输出
//    float f;
//    printf("请输入一个浮点数：");
//    scanf("%f",&f);
//    printf("输入的是这个 ==》 %f",f);

// int getchar(void) 函数从屏幕读取下一个可用的字符，并把它返回为一个整数。这个函数在同一个时间内只会读取一个单一的字符。您可以在循环内使用这个方法，以便从屏幕上读取多个字符。

// int putchar(int c) 函数把字符输出到屏幕上，并返回相同的字符。这个函数在同一个时间内只会输出一个单一的字符。您可以在循环内使用这个方法，以便在屏幕上输出多个字符。

//    char chars[10] = {};
//    printf( "Enter a value :");
//    for (int k = 0; k < 10; ++k) {
//        chars[k] = getchar( );
//    }
//    printf( "You entered: ");
//    for (int k = 0; k < 10; ++k) {
//        putchar(chars[k]);
//    }
//    printf( "\n");

//    char *gets(char *s) 函数从 stdin 读取一行到 s 所指向的缓冲区，直到一个终止符或 EOF。
//
//    int puts(const char *s) 函数把字符串 s 和一个尾随的换行符写入到 stdout。

//    char str[100];
//
//    printf( "Enter a value :");
//    gets( str );
//
//    printf( "\nYou entered: ");
//    puts( str );

//    int scanf(const char *format, ...) 函数从标准输入流 stdin 读取输入，并根据提供的 format 来浏览输入。
//
//    int printf(const char *format, ...) 函数把输出写入到标准输出流 stdout ，并根据提供的格式产生输出。
//
//    format 可以是一个简单的常量字符串，但是您可以分别指定 %s、%d、%c、%f 等来输出或读取字符串、整数、字符或浮点数。

    // str 本身就是引用
//    char str[100];
//    int ii;
//
//    printf( "Enter a value :");
//    scanf("%s %d", str, &ii);
//
//    printf( "\nYou entered: %s %d ", str, ii);
//    printf("\n");




    // 终止 main() 函数，并返回值 0
    return 0;
}


