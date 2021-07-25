//
//  stackwithlinkedlist.cpp
//  ds
//
//  Created by 李昌日 on 2021/7/25.
//

#include <stdio.h>
#include <iostream>

typedef struct StackWithLinkedList *stackll;
struct StackWithLinkedList{
    int data;
    stackll pnext;
};
//创建一个空表
// 好像这种创建一个空的根本没有意义
// 反而会混乱 数量就乱了
stackll makeEmpty(){
    // 这种创建一个新的一定要分配内存 一个
    stackll headNode = (stackll)malloc(sizeof(struct StackWithLinkedList));
    // 初始化
    headNode->pnext = NULL;
    // 因为我定义了一个头节点
    return headNode;
}
// 测量长度
int lengthcalcu(stackll node){
    stackll temp = node;
    //if(node->pnext == NULL){
    //    printf("The stack is empty!!!!!\n");
  //      return NULL;
//    }
    int len = 0;
    //直到下一个是NULL
    while(temp ->pnext != NULL){
        temp = temp->pnext;
        len  = len+1;
    }
    printf("the length is %d.\n",len);
    return len;
}

// 找到第i个位置对应的值
stackll findi(int is,stackll node){
    //如果空的情况
    stackll temp = node;
    int index = 0;
    while(index != is){
        if(temp->pnext == NULL){ // 直接筛选判断
            printf("wrong");
            return NULL;
        }
        else{
        temp  = temp->pnext;
        index++;
        }
    }
    return temp;
}

// 找到num值对应的位置
stackll findv(int num,stackll node){
    //如果空的情况
    stackll temp = node->pnext;
    //int le = lengthcalcu(temp);
    if(temp == NULL){
        printf("The list is empty.\n");
        return NULL;
    }
    int index = 1;
    while (temp->data!= num) {
        if(temp->pnext == NULL){
            printf("no such value in the list\n");
            return NULL;
        }else{
        temp = temp->pnext;
        index ++;}
    }
    printf("the %d th is %d\n",index,num);
    return temp;
}

// 因为是push 和pop
// 单向链表的头做栈顶 都是从头插入
stackll push(int num,stackll node){
    // 如果一开始是空集的话
    //lengthcalcu(node);
    stackll t = makeEmpty();
    if(node->pnext == NULL){
        node->pnext = t;
        t->data = num;
        //t->pnext = NULL;
        printf("the first is %d.\n",num);
      //  lengthcalcu(node);
        return node;
    }
    t -> data = num;
    t->pnext = node ->pnext;
    node->pnext = t;//更换头节点
    
    //
    int len = lengthcalcu(node);
    stackll tempf = t;
    for (int j=1;  j<= len;j++ ) {
        printf("%d ",tempf->data);
        tempf = tempf->pnext;
    }
    printf("\n");
    
    return node;
}
// pop
stackll pop(stackll node){
    //这是指针变量
    // 如果空的话
    if(node->pnext == NULL){
        printf("empty list");
        return NULL;
    }
    stackll t = node->pnext;//
    node->pnext = t->pnext;
    free(t);
    
    int len = lengthcalcu(node);
    stackll tempf = node->pnext;
    for (int j=1;  j<= len;j++ ) {
        printf("%d ",tempf->data);
        tempf = tempf->pnext;
    }
    printf("\n");
    return node;

}

int main(){
    stackll newnode = makeEmpty();
    //(stackll)malloc(sizeof(struct StackWithLinkedList));
    
   // lengthcalcu(newnode);
    push(2,newnode);
    push(3,newnode);
    push(4,newnode);
    push(5,newnode);
    push(6,newnode);
    push(7,newnode);
    pop(newnode);
    pop(newnode);
    stackll nnode = findi(1, newnode);
    printf("1th is %d\n",nnode->data);
    nnode = findi(4, newnode);
    printf("4th is %d\n",nnode->data);
    
    findv(4, newnode);
    findv(6, newnode);


    
    
    return 0;
}
