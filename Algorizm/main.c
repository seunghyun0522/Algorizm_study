#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

typedef struct NODE {    // 연결 리스트의 노드 구조체
    struct NODE *next;    // 다음 노드의 주소를 저장할 포인터
    int data;             // 데이터를 저장할 멤버
}NODE;


void addFirst(NODE*target, int data){
    NODE *newNode = malloc(sizeof(NODE));
    newNode->next = target->next;
    newNode->data = data;
    target->next = newNode;
}

void removeFirst(NODE*target){
    NODE *removeNode = target->next;
    target->next = removeNode->next;
    free(removeNode);
}
void nodePrint(NODE *curr){
    while(curr!=NULL){
        printf("%d\n",curr->data);
        curr = curr->next;
    }
    printf("-------------\n");
}

void nodeFree(NODE *curr){
    while(curr!=NULL){
        NODE *next = curr->next;
        free(curr);
        curr = next;
    }

}

void addEnd(NODE * target, int data){
    
}
int main()
{
    NODE *head = malloc(sizeof(NODE));    // 머리 노드 생성
                                                        // 머리 노드는 데이터를 저장하지 않음
    head->next = NULL;

    addFirst(head, 10);    // 머리 노드 뒤에 새 노드 추가
    addFirst(head, 20);    // 머리 노드 뒤에 새 노드 추가
    addFirst(head, 30);    // 머리 노드 뒤에 새 노드 추가
    
    addEnd(head,40);
    addEnd(head,50);
    NODE* curr = head->next;
    nodePrint(curr);
    removeFirst(head);
    
    curr = head->next;
    
    nodePrint(curr);
  
    curr = head->next;
    
    nodeFree(curr);
    free(head);


    return 0;
}
