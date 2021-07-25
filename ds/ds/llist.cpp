//
//  llist.cpp
//  ds
//
//  Created by 李昌日 on 2021/7/24.
//

// 这一节 学习一下链表

#include <iostream>
#include <stdio.h>

typedef struct LinkedList * llist; //define second name
// define new linked list data structure
struct LinkedList{
    int data;// data
    llist pnext;// point to the next node
};

// initialize a blank linkedlist
llist makeEmpty(){
    //create an node memeory for it
    llist p = (llist)malloc(sizeof(struct LinkedList));
    p->pnext = NULL;
    return p;

}

// calculate the length;
int callengt(llist lpt){
    llist pt = lpt;
    int len = 0;//define the length variable
    
    while(pt->pnext != NULL){
        pt = pt->pnext;
        len++;
    }
    printf("this linkedlist is measure as %d length.\n",len);
    return len;
}

// find ith value in the linked list；
llist findi(int index, llist lpt){
    // temp v to help;
    llist pt = lpt;
    int llength = callengt(pt);//calculate the value the input parameter.
    if(index < 1 || index > llength){
        printf("there is no %d th value in this linked list",index);
        return NULL;//？？ in this situation， which value should i back?
    }
    if(pt->pnext == NULL){
        printf("This is a blank linked list");
        return pt;
    }
    int lindex = 1;
    while(lindex != index ){
        pt = pt->pnext;
        lindex ++;
        
    }
    printf("the %d th value in this linkedlist is %d\n",index,pt->data);
    return pt;
}

//find the certain num value in the linked list
llist findv(int num, llist lpt){
    llist pt = lpt;
    if(pt->pnext == NULL){
        printf("This is a blank linked list");
        return pt;
    }
    int ldata = pt -> data;
    int ind  = 1;//calculate the index
    // what if there is no such value in the linked list
    while(ldata != num){
        if(pt->pnext != NULL){
        pt = pt->pnext;
        ldata = pt->data;
        ind++;
        }
        else{
            printf("there is no %d in this linked list",num);
            return pt;
        }
    }
    printf("the %d value is the %d th in the list",num,ind);
    return pt;
}

//insert num in ith of the linked list；
llist insertvi(int num , int i,llist ptl){
    llist pt = makeEmpty();
    // if the input llist ptrl is empty
    if(i == 1){
        pt->data = num;
        pt->pnext = ptl;
        return pt;
    }
    int llength = callengt(ptl);
    if(i < 1 || i > llength+1){
        printf("there is no %d th value in this linked list",i);
        return ptl;//？？ in this situation， which value should i back?
    }

    llist ptemp = makeEmpty();
    pt = findi(i-1,ptl);//imagein the insert need a tempvalue to avoid loss the adress of followingg node
    ptemp->pnext = pt->pnext;
    pt->pnext = ptemp;
    ptemp->data = num;
    return ptl;
}
//
//delete the certain ith value in the linked list
llist deletv(int i,llist ptl){
    int llength = callengt(ptl);
    if(i < 1 || i > llength){
        printf("there is no %d th value in this linked list",i);
        return ptl;//？？ in this situation， which value should i back?
    }
    if(ptl->pnext == NULL){
        printf("This is a blank linked list");
        return ptl;
    }
    llist pt = makeEmpty();
    if(i == 1){
        pt = ptl;
        ptl = ptl->pnext;
        free(pt);
        return ptl;
    }
    llist ptemp = makeEmpty();
    pt = findi(i-1,ptl);//imagein the insert need a tempvalue to avoid loss the adress of followingg node
    ptemp = pt->pnext;
    pt->pnext = ptemp->pnext;
    free(ptemp);
    return ptl;

    
    return ptl;
}

void printfTab(llist ptrl){
    llist p = ptrl;
    while(p->pnext!=NULL){
        printf("%d\n",p->data);
        p = p->pnext;
    }
   // return 0;
}

int main5(void){
    llist plist = makeEmpty();// define a new llist variavble
    callengt(plist);
    plist = insertvi(1 ,1,plist);
    callengt(plist);
    printfTab(plist);
    plist = insertvi(2 ,1,plist);
    callengt(plist);
    printfTab(plist);
    plist = insertvi(3 ,1,plist);
    callengt(plist);
    printfTab(plist);
    plist = insertvi(2 ,4,plist);
    callengt(plist);
    printfTab(plist);

    plist = deletv(1,plist);
    callengt(plist);
    printfTab(plist);
    plist = deletv(2,plist);
    callengt(plist);
    printfTab(plist);
    
   // llist plist1 = findv(1, plist);//返回值会修改 初始地址 一定要注意
    //llist plist2 = findi(1, plist);//返回值会修改 初始地址 一定要注意
    return NULL;
}
