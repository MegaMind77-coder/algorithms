#include<stdio.h>
#include<stdlib.h>

void merge(long a[],long l[],long r[],int n)//merge function takes array,amd the two sorted array(l,r) as input and merges them to find a final sorted array,n is the size of the array
{
	
  int i=0;
  int j=0;
  int k=0;
  while(i<n/2 && j<(n-n/2))
  {
      if(l[i]<=r[j])//compares the elements of the two array to overwrite the minimum in the array 'a'
      {
        a[k]=l[i];
        i+=1;
        k+=1;//moves the index of 'a' ahead to fill next element
      }
      else if(l[i]>r[j])
      {
        a[k]=r[j];
        j+=1;
        k+=1;
      }
  }
  while(i<n/2)//checks if left or right array is completely used,remaining parts of the array are then added to 'a',which are not present in a
  {
      a[k]=l[i];
      k+=1;
      i+=1;
  }
  while(j<(n-n/2))
  {
      a[k]=r[j];
      k+=1;
      j+=1;
  }

}
void mergesort(long a[],int n)//mergesort, sorts the subarrays and gives it to merge for final combinatin of sorted subarrays,'n' is the size of the array
{
   if (n<2)//if the length of the subarray is less than 2, this means that it's only one element;therefore the return statement simply exits the recusion,to reach the merge function in mergesort function
       return;
  else
  {
    long l[n/2];//creates a left subarray
    long r[n-(n/2)];//creates right subarray
    int x=0;
    int y=n/2;
    int z=0;
    int m;
    while(x<(n/2))//this loop starts filling elements in the left  array
    {
     l[x]=a[x];

     x+=1;
    }
    while(y<n && z<(n-n/2))//this loops fills elements in the right array
    {
     r[z]=a[y];
     z+=1;
     y+=1;
    }

    mergesort(l,n/2);//recursive to mergesort left array
    mergesort(r,(n-n/2));//recursive call to merge right array
    merge(a,l,r,n);//calls merge function to sort left and right subarrays,recursively
    //til the final array 'a' gets sorted 
  } 

 }

int main()
{
    long arr[] = {3,1,5,2,8};
    int n = sizeof(arr)/sizeof(long);
    mergesort(arr,n);
    for(int i = 0;i < n ; i++){
        printf("%ld ",arr[i]);
    }
    return 0;
}