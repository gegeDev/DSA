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
        }
    }
}
