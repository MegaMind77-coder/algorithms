#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000

int top = -1;


void push(int stack[],int x){
    top+=1;
    stack[top] = x;
}

void pop(int stack[]){
    top-=1;
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
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(height)/sizeof(int);
    int b[n];
    int
    for(int i=0;i<n;i++){
        if(height[i]!=0){
            if(top<0){
                push(stack,i);
            }
            else if(height[stack[top]]>height[i]){
                push(stack,i);
            }
            else{
                while()
            }
        }
    }
    return 0;
}