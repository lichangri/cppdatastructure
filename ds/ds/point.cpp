//
//  point.cpp
//  ds
//
//  Created by 李昌日 on 2021/7/24.
//

#include <stdio.h>
#include <stdlib.h>

int main1(void){
    int i = 0;
    
    i = 10;
    
    int *p = &i;
    // 这句话是两个部分来的第一部分是定义一个指针变量 int * p
    // 然后才是对这个变量进行赋值；
    
    
    
    // 取i这个值的地址 &i
    printf("&i:%p\n",&i);
    printf("p:%d\n",*p); //访问指针的值
    
    
    return 0;
    
}
