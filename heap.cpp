#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#define maxSize 1000000
using namespace std;

class Heap{
    int array[maxSize];
    int last = 0;
    void fix(int);
public:
    Heap(vector<int> &a){
        for(int i = 0; i < a.size(); i++){
            insert(a[i]);
        }
    }
    void insert(int);
    void show();
    void hSort();
    int pop();
};

int main(){
    /*int n;
    vector<int> t;
    Heap h1(t);
    while(true){
        cout << "1. insert" << endl << "2. pop" << endl << "3. hSort" << endl;
        cin >> n;
        if(n == 1){
            cin >> n;
            h1.insert(n);
        }else if(n == 2){
            n = h1.pop();
            cout << n << endl;
        }else if(n == 3){
            h1.hSort();
        }
        h1.show();
    }*/
    vector<int> tab;
    clock_t start, stop;
    srand(time(NULL));
    for(int i = 0; i < maxSize; i++){
        tab.push_back(rand() % 10000);
    }
    start = clock();
    Heap h1(tab);
    h1.hSort();
    stop = clock();
    tab.clear();
    cout << (double)(stop - start) / CLOCKS_PER_SEC << endl;
    for(int i = 0; i < maxSize; i++){
        tab.push_back(rand() % 10000);
    }
    start = clock();
    sort(tab.begin(), tab.end());
    stop = clock();
    cout << (double)(stop - start) / CLOCKS_PER_SEC << endl;
    return 0;
}

void Heap::insert(int a){
    array[last++] = a;
    for(int i = last - 1; array[i] > array[i/2];){
        swap(array[i], array[i/2]);
        i = i/2;
    }
}

void Heap::show(){
    for(int i = 0; i < last; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void Heap::hSort(){
    int temp = last;
    for(int x = 0; x < last - 1; x++){
        swap(array[0], array[--temp]);
        fix(temp);
    }
}

void Heap::fix(int l){
    int i = 0;
    while(2 * i + 1 < l){
        if(2 * i + 2 < l && array[2 * i + 2] > array[2 * i + 1] && array[2 * i + 2] > array[i]){
            swap(array[i], array[2 * i + 2]);
            i = 2 * i + 2;
        }else if(array[2 * i + 1] > array[i]){
            swap(array[2 * i + 1], array[i]);
            i = 2 * i + 1;
        }else{break;}
    }
}

int Heap::pop(){
    int e = array[0];
    swap(array[0], array[--last]);
    fix(last);
    return e;
}
