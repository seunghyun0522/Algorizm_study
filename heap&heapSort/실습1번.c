#include <stdio.h>
#include <stdlib.h>
int n =0;
void insertItem(int *H, int k);
void upHeap(int *H,int i);
void swapElement(int *A, int *B);
int removeMax(int *H);
void downHeap(int *H,int i);
void printHeap(int *H);
int main(){
    int H[100];
    char key;
    int deleteElement;
    int k;
    while(key!='q'){
        scanf("%c",&key);
        switch(key){
            case 'i': {
                scanf("%d",&k);
                insertItem(H,k);
                printf("0\n");
                break;
            }
            case 'd':{
                deleteElement = removeMax(H);
                printf("%d\n",deleteElement);
                break;
            }
            case 'p':{
                printHeap(H);
                break;
            }
        }
        getchar();
    }
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

void printHeap(int *H){
    for(int i=1;i<=n;i++)
        printf("%d ",H[i]);
    printf("\n");
}
