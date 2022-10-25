#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *link;
}Node;

typedef struct Node_h {
    Node *head;
}Node_h;

typedef struct twoList {
    Node_h *L1;
    Node_h *L2;
}twoList;

Node *getNode(void);
Node_h *createList(void);
Node *addList(Node_h *, Node *, int);
int sizeList(Node_h *);

void mergeSort(Node_h **);
Node_h *merge(Node_h *, Node_h *);
twoList partition(Node_h *, int);
void printList(Node_h*);

int main() {
    Node_h *L = NULL;
    Node *last = NULL;
    int n, K;
    L = createList();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &K);
        last = addList(L, last, K);
    }

    mergeSort(&L);
    printList(L);


}
void printList(Node_h *L) {
    Node *tmp = L->head;
    while (tmp != NULL) {
        printf(" %d", tmp->data);
        tmp = tmp->link;
    }
    printf("\n");
}
Node *getNode(void) {
    Node *newNode;
    newNode = (Node *)malloc(sizeof(newNode));
    newNode->link = NULL;
    return newNode;
}
Node_h *createList(void) {
    Node_h *L;
    L = (Node_h*)malloc(sizeof(Node_h));
    L->head = NULL;
    return L;
}
Node *addList(Node_h *L, Node *last, int key) {
    Node *n = getNode();
    n->data = key;
    if (L->head == NULL) {
        L->head = n;
    }
    else
        last->link = n;
    return n;
}
int sizeList(Node_h *L) {
    int size = 0;
    Node *tmp = L->head;
    while (tmp != NULL) {
        size++;
        tmp = tmp->link;
    }
    return size;
}
void mergeSort(Node_h **L) {
    twoList TL;
    int size = sizeList(*L);
    if (size > 1) {
        //분할
        TL = partition(*L, size / 2);
        //재귀
        mergeSort(&(TL.L1));
        mergeSort(&(TL.L2));
        //합병
        *L = merge(TL.L1, TL.L2);
    }

}
twoList partition(Node_h *L, int k) {
    Node *start = L->head;
    Node *mid = L->head, *prev;
    twoList TL;
    TL.L1 = createList();
    TL.L2 = createList();
    while (k) {
        prev = mid;
        mid = mid->link;
        k--;
    }
    prev->link = NULL;
    (TL.L1)->head = start;
    (TL.L2)->head = mid;

    return TL;
}
Node_h *merge(Node_h *L1, Node_h *L2) {
    Node_h *L3;
    L3 = createList();
    Node *L1_pos = L1->head;
    Node *L2_pos = L2->head;
    Node *L3_pos = NULL;
    Node *save = NULL;


    while (L1_pos != NULL && L2_pos != NULL) {
        if (L1_pos->data < L2_pos->data) {
            if (L3->head == NULL) {
                L3->head = L1_pos;
                //가상으로 L3에 있다고 존재
                L3_pos = L1_pos;
            }
            else {
                //L1의 존재 데이터가 L2보다 작다면, 현재 L3에 존재하는 리스트는  또 L1
                L3_pos->link = L1_pos;
                L3_pos = L1_pos;
            }

            //L3리스트에 (가상으로) 추가했으니 전진
            L1_pos = L1_pos->link;
        }
        else {
            if (L3->head == NULL) {
                L3->head = L2_pos;
                L3_pos = L2_pos;
            }
            else {
                L3_pos->link = L2_pos;
                L3_pos = L2_pos;
            }
            L2_pos = L2_pos->link;
        }
    
    }
    if (L1_pos != NULL)
        L3_pos->link = L1_pos;
    if (L2_pos != NULL)
        L3_pos->link = L2_pos;
    return L3;
}
