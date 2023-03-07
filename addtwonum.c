//
// Created by xiangming.fang on 2023/3/6.
//

// extern的用法，说明不是这个c文件内部的值，是其它文件的值
// 当使用 extern 关键字时，不会为变量分配任何存储空间，而只是指示编译器该变量在其他文件中定义。
extern int x,y;

int addtwonum(){
    return x + y;
}

