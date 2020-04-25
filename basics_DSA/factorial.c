#include <stdio.h>
#include <string.h>
 int multiply(int result[],int x,int size)
    {
        int carry=0;
        int sum;
        int j=0;
        for(int i=0;i<size;i++)
        {
            sum = 0;
            sum = carry + result[i]*x;
            carry = sum/10;
            result[i] = sum%10;
        }
        if(carry>0){
            result[size]=carry;
            size++;
        }
       /* for(int i=size-1;i>=0;i--)
        {
            printf("%d",result[i]);
        }*/
       // printf("\n");
        return size;

    }
    
    void factorial(int n)
    {
        int result[1000];
        result[0] = 1;
        int size = 1;
        int resize;
        for(int i=2;i<=n;i++)
        {
            resize = multiply(result,i,size);
            size = resize;
        }
        for(int i= size -1;i>=0;i--)
        {
            printf("%d",result[i]);
        }
    }




int main()
{
    int n;
    scanf("%d",&n);
   // int result[1000000];

    factorial(n);
    return 0;
}
