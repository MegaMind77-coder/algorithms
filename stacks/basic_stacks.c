#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000

int top = -1;//top is made a global variable on purpose

void push(int stack[],int x){
    top+=1;
    stack[top] = x;
}

void pop(int stack[]){
    top-=1;
   // return stack[*top+1];
}

int topElement(int stack[]){
    return stack[top];
}

int isEmpty(int stack[]){
    if(top == -1){
        return 1;
    }
    return 0;
}

int stack_size(int stack[]){
    return top+1;
}

int main()
{
    int stack[MAX];
    return 0;
}