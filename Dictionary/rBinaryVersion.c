#include<stdio.h>
#include<stdlib.h>

int findElementKey(int k,int l,int r, int *arr);
int main(){
    
    int *arr;
    int n,k;
    int find;
    scanf("%d %d",&n,&k);
    
    arr = (int*)malloc(sizeof(int)*n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    find = findElementKey(k,0,n-1,arr);
    printf("%d",find);
}

int findElementKey(int k,int l,int r, int *arr){
    if(l>r) {
        if(l!=0) return l-1;
        return -1;
    }
    int mid = (l+r)/2;
    
    if(k==arr[mid]) return mid;
    else if(k<arr[mid])return findElementKey(k, l, mid-1,arr);
    else return findElementKey(k, mid+1, r,arr);
}
