#include <stdio.h>
int main()
{
 long arr[20];//declaring array to store variables
 for(int x=0;x<20;x++)
 {
   scanf("%ld,",&arr[x]);//taking user input in array
 }
 int swap=0;//to count number of swaps
 int comp=0;//to count number of comparisons
 long t; //temporary variable
 int j=19;
      while(j>=1)
      {
	  
	 
	  for(int i=0;i<j;i++)
		{
			if(arr[i]>arr[i+1])//compares the consecutive numbers and places the smaller one before by swaping
			{
			swap+=1;//counts the number of swaps 	  
			t=arr[i+1];
			arr[i+1]=arr[i];
			arr[i]=t;
			}
			
	    }

		comp+=j;//counts number of comparisons 
		j=j-1; 
      }
 for(int k=0;k<20;k+=1)
 {
	 printf("%ld ",arr[k]);//prints the sorted array
 }
 
 printf("\n%d %d",swap,comp);//prints number of swaps and comparisons 
 return 0;
}
