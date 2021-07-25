//
//  twostackwitharray.cpp
//  ds
//
//  Created by 李昌日 on 2021/7/25.
//
//这里做的是数组实现两个栈
#include <stdio.h>
#include <iostream>

#define MaxSize 100

typedef struct BiStack * bStack;
struct BiStack{
    int Data[MaxSize];
    int Top1;
    int Top2;//左右两边不同的栈顶
};

bStack makeEmpty(){
    bStack pnode = (bStack)malloc(sizeof(struct BiStack));
    pnode->Top1 = -1;
    pnode->Top2 = MaxSize;
    return pnode;
}

//push
void push(int num,bStack node,int tag){
    if(node->Top2 - node->Top1 == 1){//相差一的时候堆栈就满了
        printf("堆栈满");
        return ;
    }
    if (tag == 1) {
        //就是左半边入栈
        node->Top1++;
        node->Data[node->Top1] = num;
    }else{
        //右半边入栈
        node->Top2--;
        node->Data[node->Top2] = num;
    }
}

//pop
int pop(bStack node,int tag){
    if (tag == 1) {
        //就是左半边出栈
        if (node->Top1==-1) {
            printf("the stack 1 is empty");
            return NULL;
        }
        int ind = node->Data[node->Top1] ;
        node->Top1--;
        return ind;
    }else{
        if (node->Top2==MaxSize) {
            printf("the stack 1 is empty");
            return NULL;
        }
        //右半边入栈
        int ind = node->Data[node->Top2];
        node->Top2++;

        return ind;
    }
}

int main(){
    bStack newnode = makeEmpty();
    printf("%d,%d",newnode->Top1,newnode->Top2);
    return 0;
    //
    
}
