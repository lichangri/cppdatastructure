//
//  main.cpp
//  demo
//
//  Created by 李昌日 on 2021/7/21.
//
// 数据结构 线性表 C++ 实现顺序表
// 顺序表的主要操作 增 删 查
//


#include <iostream>
#define MaxSize 100

// 建立一个空表 + 数组
// 应用什么场景
// 为什么
typedef struct shunxubiao *Listlcr ;
struct shunxubiao{
    int data[MaxSize];//这是c里面的数组吗 c++需要注意什么 又别的用法吗 vector特性在哪里 填不满数据放哪里
    int lastindex;// c 和c++中结构一样的吗
}ll;// 这里是在定义一个新的数据类型还是 定义一个这种数据类型的新变量

// 表的增加元素 第i个位置增加元素 num
struct shunxubiao addt(int i,int num,struct shunxubiao *Listlcr){
    if(Listlcr->lastindex == MaxSize){
        printf("顺序表已经满了");
        return *Listlcr;// 返回一个错误值 怎么返回 他说必须返回一个struct shunxubiao 类 不能返回NULL
    }
    if(i < 0||i> Listlcr->lastindex-1){
        printf("输入位置错误");
        return *Listlcr;
    }
    for(int j = Listlcr->lastindex;j < i-1;j--){
        Listlcr->data[j+1] = Listlcr->data[j] ;
    }
    Listlcr->data[i-1] = num;
    Listlcr->lastindex = Listlcr->lastindex + 1;
    return *Listlcr;
}

//表 找元素 第i个元素
int findi(int i,struct shunxubiao *Listlcr){
    if(Listlcr->lastindex == 0){
        printf("顺序表空的");
        return 0;//
    }
    if(i < 0 || i> Listlcr->lastindex-1){
        printf("输入位置错误");
        return 0;
    }
    return Listlcr->data[i-1];
}

// 表 找和某个元素一样的值的index 的第一个
// 如果是很多个该怎么返回 因为屎了 int[maxsize] findv 报错
int findv(int num,struct shunxubiao *Listlcr){
    if(Listlcr->lastindex == 0){
        printf("顺序表空的");
        return NULL;//
    }
    int index;
    for(int j =0; j<Listlcr->lastindex;j++){ // 循环至少跑一次是什么意思
        if(Listlcr->data[j] == num){
            index = j+1;
            return index;
        }
    }
    printf("线性表里没有这个值");
    return NULL;
    }// 这里经常报错是因为返回值嘛

//删除操作 删除第i个数
struct shunxubiao deletev(int i,struct shunxubiao *Listlcr){
    if(Listlcr->lastindex == 0){
        printf("表空");
        return *Listlcr;
    }
    if(i<0 || i>Listlcr->lastindex-1){
        printf("位置错误");
        return *Listlcr;
    }
    for(int j = i-1;j<Listlcr->lastindex-2;j++){
        Listlcr->data[j] = Listlcr->data[j+1];
    }
    Listlcr->lastindex = Listlcr->lastindex+1;
    return *Listlcr;
    
}



int main(int argc, const char * argv[]) {
    
    
    
}
