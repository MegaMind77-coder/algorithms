#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char bin(unsigned n) 
{ 
    if (n > 1) 
    bin(n>>1); 
      
    return (char)(n&1);
} 

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

long long int large_power(char *bin,int n,int x){
  //  printf("%s",bin);
    long long int a = iterative_power(x,2);
    long long int final = 0;
    for(int i=n-1;i>=0;i--){
        if(bin[i]==1){
            final += iterative_power(a,n-1-i);            
        }
    }
    return final;
}

int main(){
    char *s = "11";
    printf("%lld",large_power(s,strlen(s),1));
    return 0;
}