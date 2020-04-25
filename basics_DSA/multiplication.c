#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char a[]="10000000000";
	char b[]="100000";
	int na = strlen(a);
	int nb = strlen(b);
	int x[1000000],y[1000000];
    int ans[na+nb];
	char result[100];
	for(int i=0,j=na-1;i<na,j>=0;i++,j--)
	{
		x[i]=a[j]-'0';
	}
	for(int i=0,j=nb-1;i<nb,j>=0;i++,j--)
	{
		y[i]=b[j]-'0';
	}
	for(int i=0;i<na+nb;i++)
	{
		ans[i]=0;
	}
	for(int i=0;i<nb;i++)
	{
		for(int j=0;j<na;j++)
		{
			ans[i+j] += y[i]*x[j];
		}
	}
	int sum,carry=0;
	int i;
	for(i=0;i<na+nb;i++)
	{
		sum=0;
		sum=ans[i]+carry;
		result[i]=sum%10+'0';
		carry=sum/10;
	}
	if(carry>0)
	{
		result[i]=carry+'0';
	}
	for(int i=strlen(result);i>=0;i--)
	{
		printf("%c",result[i]);
	}
}