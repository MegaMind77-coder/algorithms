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

int stack[MAX];
int validate(int pushed[],int pushed_size,int popped[],int popped_size){
    int p_push,p_pop=0;
    while(p_push<=pushed_size && p_pop<popped_size){
        if(top<0){
            push(stack,pushed[p_pop]);
            p_pop+=1;
        }

        if(stack[top] == popped[p_pop]){
            pop(stack);
            p_pop+=1;
        }
        else if(p_push<pushed_size && stack[top]!=popped[p_pop]){
            push(stack,pushed[p_pop]);
            p_pop+=1;
        }
        else
        {
            break;
        }
    }
    if(p_push == pushed_size && p_pop == popped_size){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    int pushed[]={1,2,3,4,5};
    int popped[]={4,5,3,2,1};
    int n1 = sizeof(pushed)/sizeof(int);
    int n2 = sizeof(popped)/sizeof(int);
    if(validate(pushed,n1,popped,n2)==1){
        printf("true");
    }
    else{
        printf("false");
    }
    return 0;
}