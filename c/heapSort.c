#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapSort(int arr[], int n){
    int temp;
    
    // Create a heap in place
    for(int i = 1; i < n; i++){
        temp = i;
        while(arr[temp] > arr[temp/2]){
            swap(&arr[temp], &arr[temp/2]);
            temp = temp / 2;
        }
    }
    
    // Sort using a heap
    int i;
    int last = n - 1;
    for(int x = 0; x < n; x++){
        i = 0;
        swap(&arr[0], &arr[last--]);
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
}

int main(){
    int tab [] = {5, 4, 3, 2, 1};
    heapSort(tab, 5);
    for(int i = 0; i < 5; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
    return 0;
}
