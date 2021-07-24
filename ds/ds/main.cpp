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
#include <stdio.h>
using namespace std;

#define MaxSize 100

// 建立一个空表 + 数组
// 应用什么场景
// 为什么
typedef struct shunxubiao * Listlcr ;// 这个放在哪里 定义的是别名 定义了之后就用别名
struct shunxubiao{
    int data[MaxSize];//这是c里面的数组吗 c++需要注意什么 又别的用法吗 vector特性在哪里 填不满数据放哪里
    int lastindex;// c 和c++中结构一样的吗
};// 这里是在定义一个新的数据类型还是 定义一个这种数据类型的新变量
//Listlcr Pt; 定义一个结构体指针变量

//关于指针的操作

// 初始化 创建一个空表
Listlcr MakeEmpty(){
    Listlcr Pt;
    Pt = (Listlcr)malloc(sizeof(struct shunxubiao));
    Pt -> lastindex = -1;
    return Pt;
}


// 表的增加元素 第i个位置增加元素 num
// *号怎么用
Listlcr addt(int i,int num,Listlcr ptrl){
    if(ptrl->lastindex == MaxSize-1){
        printf("顺序表已经满了");
        return ptrl;// 返回一个错误值 怎么返回 他说必须返回一个struct shunxubiao 类 不能返回NULL
    }
    // 如果是从一个空的顺序表插入的话
    if(ptrl->lastindex == -1){
        ptrl->lastindex = 0;
        ptrl->data[0] = num;
        return ptrl;
    }

    if(i < 0||i> ptrl->lastindex+1){
        printf("输入位置错误");
        return ptrl;
    }
    
    // for循环为什么没进去 第二个条件为正 就执行
    for(int j = ptrl->lastindex;j>=i-1;j--){
        ptrl->data[j+1] = ptrl->data[j] ;
    }
    ptrl->data[i-1] = num;
    ptrl->lastindex = ptrl->lastindex + 1;
    return ptrl;
}

//表 找元素 第i个元素
int findi(int i,Listlcr ptrl){
    if(ptrl->lastindex == 0){
        printf("顺序表空的");
        return 0;//
    }
    if(i < 0 || i> ptrl->lastindex-1){
        printf("输入位置错误");
        return 0;
    }
    return ptrl->data[i-1];
}

// 表 找和某个元素一样的值的index 的第一个
// 如果是很多个该怎么返回 因为屎了 int[maxsize] findv 报错
int findv(int num,Listlcr ptrl){
    if(ptrl->lastindex == 0){
        printf("顺序表空的");
        return NULL;//
    }
    int index=0;
    for(int j =0; j<=ptrl->lastindex;j++){ // 循环至少跑一次是什么意思
        if(ptrl->data[j] == num){
            index = j+1;
            return index;
        }
    }
    printf("线性表里没有这个值");
    return NULL;
    }// 这里经常报错是因为返回值嘛

//删除操作 删除第i个数
Listlcr deletev(int i,Listlcr ptrl){
    if(ptrl->lastindex == 0){
        printf("表空");
        return ptrl;
    }
    if(i<0 || i>ptrl->lastindex+1){
        printf("位置错误");
        return ptrl;
    }
    for(int j = i-1;j< ptrl->lastindex ;j++){
        ptrl->data[j] = ptrl->data[j+1];
    }
    ptrl->lastindex = ptrl->lastindex-1;
    return ptrl;
    
}

void printfTable(Listlcr ptrl){
    int index = ptrl->lastindex;
    printf("\n");
    for(int j = 0;j<=index;j++){
       printf("%d",ptrl->data[j]);
    }
    printf("\n");
}

int main2(int argc, const char * argv[]) {
    Listlcr Ptt;
    // 创建一个新表 然后不断的通过软件
    Ptt = MakeEmpty();//函数 的调用；
    Ptt = addt(1,3,Ptt);//函数调用 *号的使用 一定要match
    printfTable(Ptt);
    Ptt = addt(1,5,Ptt);//
    printfTable(Ptt);
    Ptt = addt(1,8,Ptt);//
    printfTable(Ptt);//结果很奇怪 为什么呢 因为我的for循环写错了
    Ptt = addt(1,9,Ptt);//
    printfTable(Ptt);    //删除操作
    Ptt = deletev(3,Ptt);
    printf("%d",Ptt->lastindex);
    printfTable(Ptt);
    // 找到第i个数
    int k = findv(8,Ptt);
    printf("8这个值在表的 %d 个位置\n",k);//
    
    int ky = findi(1, Ptt);
    printf("第1个位置是 %d",ky);//

    
    //printfbiao(Ptt);
    //Ptt = addt(3,7,Ptt);//
    //printfbiao(Ptt);
    return 0;
    
}
