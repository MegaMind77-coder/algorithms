#include<stdio.h>
int part(long a[],int i,int f)//creating a function that returns the position of the pivot after sorting,i is the initial index and f is the final index of the array 
{
 int x=0;
 int p=a[f];//it takes the last element of the array as pivot
 int y=0;
 for(x;x<f;x+=1)//loop rearranges the array,such that elements smaller than the pivot are on the left,and vice versa
 {
   if(a[x]<=p)
    {	
	long t;//temporary variable 
	t=a[y];
	a[y]=a[x];
	a[x]=t;
	y+=1;
    }
 }
 long z;//this part swaps the position of the pivot,to place it before elements smaller than it 
 z=a[y];
 a[y]=a[x];
 a[x]=z;
 return y;//returns the position of the pivot
}
void qsort(long a[],int i,int f)//function which take the array as input, and starts rearranging the subarrays by taking pivots 
{
   if(i<f)
     {
       int p=part(a,i,f);
       qsort(a,i,p-1);//recursively calls the function for the array to the left of the pivot
       qsort(a,p+1,f);//recursively call the part of the array to the right of the pivot
     }
}
int main()
{
  int n;
  scanf("%d",&n);
  int i=0;
  long arr[n];
  for(i;i<n;i+=1)
  {
      scanf("%ld,",&arr[i]);
  }
  i=0;
  int pivot=arr[n-1];//pivot variable stores the last element in the unsorted array 
  qsort(arr,0,n-1);//sorts the array using Quicksort
  while(i<n)//linear search for the pivot in sorted list
  {
    if (pivot==arr[i])
        break;
    i+=1;
  }
  int k=0;
  for(k;k<n;k+=1)//prints the final sorted array
  {
      printf("%ld ",arr[k]);
  }
  printf("\n%d",i);//prints the index of the the initialpivot in the sorted list
  return 0;
}


