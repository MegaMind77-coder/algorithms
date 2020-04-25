#include<stdio.h>
int main()
{
 long arr[20];//declaring array
 for(int x=0; x<20; x++)
 {
   scanf("%ld,",&arr[x]);//taking user input into the array
 }

 int swap=0;//variable to count number of swaps 
 int count=0;//variable to count number of comparisons 
 
  
 for(int i=0; i<19; i++)
 {	
	int m = i;
 	for(int j = i+1; j<20;j++)
 	{
 	  if(arr[m] > arr[j])//compares the all number in array after the ith element to find minimum 
		{	
			m=j;
		} 
	  count+=1;//counts number of comparisons 
 	}

	long t = arr[i];//swaps the ith and min element of the array
	arr[i]=arr[m];
	arr[m]=t;
	swap+=1;//counts the swaps 
	
}

 int l=0;
 while(l<20)
{
 printf("%ld ",arr[l]);//prints all the elements in the array
 l+=1;
}
printf("\n%d %d",swap,count);//prints the number of swaps and comparisons 
return 0;
}

