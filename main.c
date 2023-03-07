// 预处理器指令，告诉 C 编译器在实际编译之前要包含 stdio.h 文件
#include <stdio.h>
#include <float.h>

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



    // 终止 main() 函数，并返回值 0
    return 0;
}
