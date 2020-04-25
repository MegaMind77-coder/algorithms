#include<stdio.h>

long long int power(int x,int n){
    if(n==0)
    return 1;
    else if(n%2==0){
        return power(x*x,n/2);
    }
    else if(n%2==1){
        return x*power(x*x,n/2);
    }
}

int main(){
    printf("%lld",power(2,31));
    return 0;
}