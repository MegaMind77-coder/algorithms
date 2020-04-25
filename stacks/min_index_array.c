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

int isEmpty(int stackp[]){
    if(top == -1){
        return 1;
    }
    return 0;
}

int stack_size(int stack[]){
    return top+1;
}

int *min_indexes(int a[],int n){
    int stack[MAX];
    int *b = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        if(top<0){
            push(stack,i);
        }
        else if(a[stack[top]]<a[i]){
            push(stack,i);
        }
        else{
            while(top>=0 && a[stack[top]]>=a[i]){
                b[stack[top]] = i;
                pop(stack);
            }
            push(stack,i);
        }
    }
    while(top>=0){
        b[stack[top]] = -1;
        pop(stack);
    }
    return b;
}

int main()
{
    //int stack[MAX];
    int A[]={6,13,7,8,4,9};
    int n = sizeof(A)/sizeof(int);
    int *B = min_indexes(A,n);
    for(int i=0;i<n;i++){
        printf("%d ",B[i]);
    }
    return 0;
}