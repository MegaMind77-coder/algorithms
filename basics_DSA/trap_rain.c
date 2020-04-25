#include<stdio.h>

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int MIN(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}

int trap(int* height, int heightSize){
    int left[heightSize],right[heightSize];
    left[0] = height[0];
    right[heightSize-1] = height[heightSize-1];
    for(int i=1;i<heightSize;i++){
        if(height[i]>left[i-1]){
            left[i] = height[i]; 
        }
        else{
            left[i] = left[i-1];
        }
    }
    for(int j=heightSize-2;j>=0;j--){
        if(height[j]>right[j+1]){
            right[j] = height[j];
        }
        else{
            right[j] = right[j+1];
        }
    }
    int totalwater = 0;
    for(int i=0;i<heightSize;i++){
        totalwater+=MIN(left[i],right[i]) - height[i];
    }
    return totalwater;    
}

int main(){
    int height[] = {};
    int n = sizeof(height)/sizeof(int);
    printf("%d",trap(height,n));
}