#include<stdio.h>
#include<stdlib.h>
void rMergeSort(int *A,int l, int r);
void merge(int *A,int l,int m,int r);
int n;
int main(){
    
    int *L;
    scanf("%d",&n);
    
    L = (int*)malloc(sizeof(int)*n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&L[i]);
    }

    
    rMergeSort(L,0,n-1);
    
    for(int i=0;i<n;i++)
        printf("%d ",L[i]);
}

void rMergeSort(int *A,int l, int r){
    if(l<r){
        int m= (l+r)/2;
        rMergeSort(A, l, m);
        rMergeSort(A, m+1, r);
        merge(A, l, m, r);
    }
}

void merge(int *A,int l,int m,int r){
    int i = l;
    int k=l;
    int j = m+1;
    int *B= (int*)malloc(sizeof(int)*n);
    while(i<=m && j<=r){
        if(A[i] <=A[j]) B[k++] = A[i++];
        else B[k++]= A[j++];
    }
    
    while(i<=m) B[k++] = A[i++];
    while(j<=r)B[k++]=A[j++];
    
    for(k=l;k<=r;k++)
        A[k] = B[k];
}

