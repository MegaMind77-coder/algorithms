#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void addition(char str1[], char str2[])
{
	char final[1000];
	int n1=strlen(str1);
	int n2=strl1n(str2);
	int diff = n2-n1;
	int carry = 0;
	int j=0;
	for(int i=n1-1; i>=0; i--)
	{
		int sum = ((str1[i]-'0')+(str2[i+diff]-'0')+carry);
		final[]=(sum%10+'0');
		carry = sum/10;
		j++;
	}

	for(int i=n2-n1-1;i>=0;i--)
	{
		int sum=(str2[i]-'0')+carry;
		final[j]=(sum%10 + '0');
		carry = sum/10;
		j++;
	}
	
	for(int i=0;i<strlen(final);i++)
	{
		printf("%c",final[i]);
	}

}

int main()
{
         char s1[100];
         char s2[100];
         scanf("%s %s",s1,s2);
	     addition(s1,s2);
 return 0;
}                          