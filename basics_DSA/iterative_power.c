#include<stdio.h>

long long int iterative_power(int x,int n){
    long long int y=1;
    while(n>0){
        if(n%2==1){
            y = y*x;
        }
        x = x*x;
        n = n/2;
    }
    return y;
}

int main(){
    printf("%lld",iterative_power(2,32));    
}