//
//  stackwitharray.cpp
//  ds
//
//  Created by 李昌日 on 2021/7/25.
// to achieve the stack with the help of array
// stack : a kind of restricted list,where the data push will pop later;


#include <iostream>
#include <stdio.h>
#define MaxSize 100 //do not need coma

typedef struct StackLcr *stackList ;
struct StackLcr{
    int Data[MaxSize] ;
    int lastIndex;//the last index of the list, warning the array begin with 0;
};//claim a new array-based stack list data type

stackList makeEmpty(){
    // the most important thing in the makeempty list is to assign memory for this type;
    stackList aheadNode;
    aheadNode = (stackList)malloc(sizeof(struct StackLcr));
    aheadNode -> lastIndex = -1;// the stack list initialization with last index -1;
    return aheadNode;
}

// to insert value num to the ith place of the list
// 这一段没有任何意义 但是相对之前写的有提高 所以保留
stackList insertv(int i,int num, stackList node){

    if(i<0 || i > node -> lastIndex + 2){
        // when  i is lower than the 0, wrong parameter
        // whereas the biggest i(who begin with 1) for the list is indexIndex(who begin with 0) +1;
        // so to achieve the insertation to the list, the biggest supposed to smaller than lastIdex
        printf("there is no %d th in the list",i);
        return NULL;
    }
    // to achieve the array element insertation
   // the i:lastindex memeber of the array should to be moved to the next and to vacant the ith place for the inserted value
    for(int j = node->lastIndex;j>=i-1;j--){
        node->Data[j+1] = node->Data[j];
    }
    node->Data[i-1] = num;
    node->lastIndex = node->lastIndex+1;
    //print the array
    for(int j = 0;j<=node->lastIndex;j++){
        printf("%d ",node->Data[j]);
    }
    printf("\n");
    return node;
}
// to delete some value from the stacked list
stackList  deletev(int i, stackList node){
    if(i<0 || i > node -> lastIndex){
        printf("there is no %d th in the list",i);
        return NULL;
    }
    // pay attention for the for-loop
    for(int j = i-1;j<node->lastIndex;j++){
        node->Data[j] = node->Data[j+1];
    }
    node->lastIndex = node->lastIndex-1;
    for(int j = 0;j<=node->lastIndex;j++){
        printf("%d ",node->Data[j]);
    }
    printf("\n");
    return node;
}
// to find ith from this list
int findi(int i, stackList node){
    if(i<0 || i > node -> lastIndex+1){
        printf("there is no %d th in the list\n",i);
        return NULL;
    }
    int num = node->Data[i-1]; //cause array begin with 0
    printf("the %d th value in the list is %d\n",i,num);
    return num;
}
// 栈的特有操作 push 推入
void pushs(int num, stackList node){
    if(node->lastIndex == MaxSize -1){
        printf("this stack full .hhhhh");
    }
    else{
        node->lastIndex++;
        node->Data[node->lastIndex] = num;
        for(int j = 0;j<=node->lastIndex;j++){
            printf("%d ",node->Data[j]);
        }
        printf("\n");

        
    }
}
// 栈的特有操作 pop
int pop(stackList node){
    if(node->lastIndex == -1){
        printf("this stack empty .hhhhh");
        return NULL;
    }
    else{
        node->lastIndex--;
        for(int j = 0;j<=node->lastIndex;j++){
            printf("%d ",node->Data[j]);
        }
        printf("\n");
       return node->Data[node->lastIndex];
        
    }
}


// find certain value in the list
int findv(int num, stackList node){
    if(node -> lastIndex == -1){
        printf("this is an empty list\n");
        return NULL;
    }
    int index = 1;
    for(int j = 0;j <= node->lastIndex;j++){
        if(node->Data[j] == num){
            printf("the %d in the stack list is %d th\n",num,index);
            return index;
        }
        else
            index++;
    }
    printf("the is no %d in the stack list.\n",num);
    return index;
    }

int main(){
    stackList newnode = makeEmpty();
    newnode = insertv(1,1,newnode);
    newnode = insertv(2,2,newnode);
    newnode = insertv(3,3,newnode);
    newnode = insertv(4,4,newnode);
    newnode = insertv(5,5,newnode);
    newnode = insertv(6,6,newnode);
    newnode = insertv(6,6,newnode);
    newnode = deletev(6,newnode);
    newnode = deletev(1,newnode);
    newnode = deletev(2,newnode);
    findi(4,newnode);
    findv(4,newnode);
    findv(1,newnode);
    pushs(7, newnode);
    pop(newnode);
    //return NULL;
}
