#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int i, int last){
    while(2 * i + 1 <= last){
            if(2 * i + 2 <= last && arr[2 * i + 2] > arr[2 * i + 1] && arr[2 * i + 2] > arr[i]){
                swap(&arr[i], &arr[i * 2 + 2]);
                i = 2 * i + 2;
            }else if(arr[2 * i + 1] > arr[i]){
                swap(&arr[i], &arr[2 * i + 1]);
                i = 2 * i + 1;
            }else{break;}
        }
}

void heapSort(int arr[], int n){
    int temp;
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, i, n);
    }

    // Sort using a heap
    int i;
    int last = n - 1;
    for(int x = 0; x < n; x++){
        swap(&arr[0], &arr[last--]);
        heapify(arr, 0, last);
    }
}

// middle pivot
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

// beginning pivot
void quickSortE(int* arr, int b, int e){
    int i = b, j = e, m = arr[e]; 
    while(i <= j){
        while(arr[i] < m){i++;}
        while(arr[j] > m){j--;}
        if(i <= j){swap(&arr[i++], &arr[j--]);}
    }
    if(i < e){quickSortE(arr, i, e);}
    if(b < j){quickSortE(arr, b, j);}
}

void quickSortR(int* arr, int b, int e){
    srand(time(NULL));
    int i = b, j = e, m = arr[rand() % (e - b) +  b]; 
    while(i <= j){
        while(arr[i] < m){i++;}
        while(arr[j] > m){j--;}
        if(i <= j){swap(&arr[i++], &arr[j--]);}
    }
    if(i < e){quickSortR(arr, i, e);}
    if(b < j){quickSortR(arr, b, j);}
}

void bubbleSort(int* arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
        }
    }
}

void selectionSort(int* arr, int n){
    static int min;
    for(int i = 0; i < n; i++){
        min = i;
        for(int j = i; j < n; j++){
            if(arr[j] < arr[min]) min = j;
        }
        swap(&arr[min], &arr[i]);
    }
}
    
void insertionSort(int *arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j > 0; j--){
            if(arr[j] < arr[j - 1]) swap(&arr[j], &arr[j - 1]);
            else break;
        }
    }
}

void mergeSort(int* arr, int b, int e){
    if(b == e) return;
    mergeSort(arr, b, (b+e)/2);
    mergeSort(arr, (b+e)/2 + 1, e);

    int i = b, j = (b+e) / 2 + 1, m = (b+e)/2, x = 0;
    int *temp = malloc(sizeof(int) * (e - b + 1));
    
    while(i <= m && j <= e){
        if(arr[i] <= arr[j]) temp[x++] = arr[i++];
        else temp[x++] = arr[j++];
    }
    while(i <= m) temp[x++] = arr[i++];
    while(j <= e) temp[x++] = arr[j++];
    
    for(int i = 0; i < e - b + 1; i++) arr[b + i] = temp[i];
    free(temp);
}

void shellSort(int *arr, int n){
    for(int i = n/3; i >= 1; i = (i+1) / 3){
        for(int j = i; j < n; j++){
            for(int k = j; k >= i; k-= i){
                if(arr[k] < arr[k - i]) swap(&arr[k], &arr[k-i]);
                else break;
            }
        }
    }
}
