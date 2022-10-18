#include <stdio.h>
#include <stdlib.h>

void swapElement(int*, int*);
void upHeap(int*, int);
void downHeap(int*, int, int);
void insertItem(int*, int*, int);
int deleteKey(int*, int*);
void printHeap(int*, int N);
void main() {
	int H[100] = { 0 }, N = 0, key;
	int* Element;
	char func = '\0';

	while (func != 'q') {

		scanf("%c", &func);
		switch (func) {


			//삽입 함수 호출
		case 'i':
			scanf("%d", &key);
			insertItem(H, &N, key);
			break;
		case 'd':
			Element = deleteKey(H, &N);
			if (Element >= 1)
				printf("%d\n", Element);
			break;
		case 'p':
			printHeap(H, N);
			break;

		}
		getchar();
	}
}
void swapElement(int* A, int* B) {
	int tmp = *A;
	*A = *B;
	*B = tmp;
}
void upHeap(int* H, int i) {
	if (i == 1)
		return;
	if (H[i / 2] >= H[i])
		return;
	swapElement(&H[i / 2], &H[i]);
	upHeap(H, i / 2);

}
void downHeap(int* H, int N, int i) {
	int bigger;
	if (2 * i > N)
		return;
	bigger = 2 * i;
	if (bigger + 1 <= N)
		if (H[bigger] < H[bigger + 1])
			bigger++;
	if (H[bigger] <= H[i])
		return;
	swapElement(&H[bigger], &H[i]);
	downHeap(H, N, bigger);
}
void insertItem(int* H, int* n, int key) {
	if (*n >= 99) {
		//삽입 실패 표현
		return;
	}
	//마지막 노드 갱신 후 삽입
	(*n)++;
	H[*n] = key;
	upHeap(H, *n);

	//삽입 완료
	printf("0\n");
}
int deleteKey(int* H, int* n) {
	int old;
	if (*n == 0)
		return -1;
	old = H[1];
	H[1] = H[*n];
	H[*n] = 0;
	(*n)--;
	downHeap(H, *n, 1);
	return old;
}
void printHeap(int* H, int N) {
	for (int i = 1; i <= N; i++)
		printf(" %d", H[i]);
	printf("\n");
}
