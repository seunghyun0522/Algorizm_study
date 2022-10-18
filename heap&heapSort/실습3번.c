#include <stdio.h>
#include <stdlib.h>
int n=0;
int m=0;
void insertItem(int *H, int k);
void inPlaceHeapSort(int *K,int key);
void upHeap(int *H,int i);
void swapElement(int *A, int *B);
int removeMax(int *H);
void rBuildHeap(int *H,int i);
void downHeap(int *H,int i);
void printHeap(int *H);
void BuildHeap(int *H);
int main(){
    int *H=NULL;
    int *K=NULL;
    int key;
    int num;
    scanf("%d",&num);
    H= (int*)malloc(sizeof(int)*(num+1));
    K= (int*)malloc(sizeof(int)*(num+1));
    
    for(int i=0;i<num;i++){
        scanf("%d",&key);
        insertItem(H,key);
    }
    
    for(int i=0;i<num;i++){
        inPlaceHeapSort(K,removeMax(H));
    }
    printHeap(K);
    return 0;
}

void insertItem(int *H, int k){
    n++;
    H[n] = k;
    upHeap(H,n);
}

void upHeap(int *H,int i){
    if(i<=1)return;
    if(H[i/2]>=H[i])return;
    swapElement(&H[i/2],&H[i]);
    upHeap(H,i/2);
}

void swapElement(int *A, int *B){
    int temp =*A;
    *A = *B;
    *B = temp;
}


void inPlaceHeapSort(int *K,int key){
    m++;
    K[m]=key;
}
int removeMax(int *H){
    int deleteKey = H[1];
    H[1] = H[n];
    n--;
    downHeap(H,1);
    return deleteKey;
}

void downHeap(int *H,int i){
    if(i<1)return;
    int bigger= i*2;
    if(bigger> n) return;
    if(H[bigger] <= H[bigger+1]) bigger++;
    
    if(H[bigger]<H[i]) return;
    else swapElement(&H[bigger],&H[i] );
    downHeap(H,bigger);
}

//재귀 버전
void rBuildHeap(int *H,int i){
    if(i<=n){
        rBuildHeap(H,2*i);
        rBuildHeap(H,2*i+1);
        downHeap(H,i);
    }
}
void BuildHeap(int *H){
    for(int i=n/2;i>=1;i--) downHeap(H, i);
}

void printHeap(int *H){
    for(int i=m;i>=1;i--)
        printf("%d ",H[i]);
    printf("\n");
}
