#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int equal01(char *bin){
   int n = strlen(bin);
   int l=0;
   int r=n-1;
   int zero=0;
   int one=0;
   while(l<=r){
       while((bin[l]-'0')!=1){
        if(zero=one+1){
            break;
        }
        l++;
        zero++;
       }
       while(zero!=one && l<=r){
           if((bin[r]-'0')!=0){
               one++;
           }
           r--;
       }
    if(l<r){
          l++;
    }
   }
   if(abs(zero-one)>1){
       printf("NO");
   }
   return l;
}

int main()
{
    char bin[] = "100101";
    printf("%d",equal01(bin));
    return 0;
}