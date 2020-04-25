#include<bits/stdc++.h>
using namespace std;

int validate(int pushed[],int pushed_size,int popped[],int popped_size){
    stack<int> s;
    int pop = 0;
    int push = 0;
    for(int i=0;i<pushed_size;i++){
        s.push(pushed[i]);
        while(!s.empty() && s.top()==popped[pop] && pop<popped_size){
            s.pop();
            pop+=1;
        }
    }
    if(popped_size == pop){
        return 1;
    }
    return 0;
}

int main(){
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