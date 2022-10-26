#include <stdio.h>
#include <stdlib.h>


int binearySearch(int*, int, int, int);

void main() {
    int *arr = NULL;
    int n, k, kPos;

   scanf("%d %d", &n, &k);
    arr = (int *)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

            kPos = binearySearch(arr, 0, n - 1, k);

    printf(" %d", kPos);
    free(arr);
}
int binearySearch(int *arr, int l, int r, int k) {
    int mid;

    

    while (l <= r) {
        mid = (l + r) / 2;

        if (arr[mid] == k)
            return mid;

        else if (arr[mid] > k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

