#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int* arr, int b, int e){
    int i = b, j = e, m = arr[(b + e) / 2]; 
    while(i <= j){
        while(arr[i] < m){i++;}
        while(arr[j] > m){j--;}
        if(i <= j){swap(&arr[i++], &arr[j--]);}
    }
    if(i < e){quickSort(arr, i, e);}
    if(b < j){quickSort(arr, b, j);}
}

int main(){
    int a [] = {1, 5, 2, 4, 2, 6, 7, 9, 12, 11, 5, 16};
    quickSort(a, 0, 12);
    for(int i = 0; i < 12; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
