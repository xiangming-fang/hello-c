//
// Created by xiangming.fang on 2023/3/8.
//
#include "stdio.h"

// c 文件读写

//    1、可以使用 fopen( ) 函数来创建一个新的文件或者打开一个已有的文件,这个调用会初始化类型 FILE 的一个对象，类型 FILE 包含了所有用来控制流的必要的信息
//    FILE *fopen( const char *filename, const char *mode );

//    2、为了关闭文件，请使用 fclose( ) 函数。函数的原型如下：
//    int fclose( FILE *fpp );

//    3、把字符写入到流中的最简单的函数
//    int fputc( int c, FILE *fpp );

//    4、把一个以 null 结尾的字符串写入到流中
//    int fputs( const char *s, FILE *fpp );

//    5、从文件读取单个字符的最简单的函数：
//    int fgetc( FILE * fpp );

//    6、允许您从流中读取一个字符串：
//    char *fgets( char *buf, int n, FILE *fpp );

// 无语，只能用绝对路径，相对路径不好使
char filename[] = "D:\\study\\hello-c\\tmp\\test.txt";

void fileinputandoutput(){
    FILE *fp = NULL;

    fp = fopen(filename, "a+");
    // 往fp里面输入字符串
    fprintf(fp, "This is testing for fprintf...\n");
    // 这也是输入啊，参数位置对调了一下，为啥要两个？？？fprintf和fputs啥区别
    fputs("This is testing for fputs...\n", fp);
    fclose(fp);

    FILE *fpp = NULL;
    char buff[255];


    fpp = fopen(filename, "r");
    // fscanf 只会扫描一行的一个单词 在遇到第一个空格和换行符时,停止读取
    fscanf(fpp, "%s", buff);
    printf("1: %s\n", buff );

    // fgets 获取一行的内容，由于上面已经从fpp流中获取到了第一个单词，所以流中的第一行没有第一个单词了，所以，这里是获取第一行后面的数据
    fgets(buff, 255, fpp);
    printf("2: %s\n", buff );

    // 再获取一行
    fgets(buff, 255, fpp);
    printf("3: %s\n", buff );
    fclose(fpp);
}


int main(){

//    fileinputandoutput();

    FILE *file = NULL;
    file = fopen(filename,"wa+");
    for (int i = 0; i < 10; ++i){
        if(i < 5){
            fprintf(file,"%d: is fprintf……\n",i);
        } else{
            fputs("this is fputs……\n",file);
        }
    }
    fclose(file);

    FILE *read = NULL;
    read = fopen(filename,"r");
    char buff[255] = {};

    // todo 搞不明白，啥时候表示读取完了
    while (1){
        char *res = fgets(buff,255, read);
        printf("%s\n",buff);
        if(*res == EOF){
            break;
        }
    }
    printf("退出来了\n");
    fclose(read);

};
