#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000

void push(int stack[],int *top,int x){
    *top+=1;
    stack[*top]=x;
}

void pop(int stack[],int *top){
    *top-=1;
}

//we can declare as many stacks as possible but functions will be limited.
int main(){
    int stack[MAX];
    int top = -1;
}