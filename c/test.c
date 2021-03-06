#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sortingAlgos.h"

int main(){
    int n;
    scanf("%d", &n);
    int *a = malloc(sizeof(int) * n);
    int *b = malloc(sizeof(int) * n);
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        a[i] = rand() % (n * 2);
        b[i] = rand() % (n * 2);
    }
    
    clock_t start, stop;
    start = clock();
    shellSort(a, n);
    stop = clock();
    printf("Shell Sort time: %g\n", (double)(stop - start) / CLOCKS_PER_SEC);
    
    /*start = clock();
    quickSortR(a, 0, n);
    stop = clock();
    printf("Quick sort time: %.9f\n", (double)(stop - start) / CLOCKS_PER_SEC);*/
    
    /*start = clock();
    mergeSort(a, 0, n - 1);
    stop = clock();
    printf("Merge sort time: %g\n", (double)(stop - start) / CLOCKS_PER_SEC);*/

    return 0;
}
