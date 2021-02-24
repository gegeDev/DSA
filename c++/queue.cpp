#include <iostream>
using namespace std;

class Queue{
    struct Item{int val; Item *next = NULL;};
    Item *first = NULL;
    Item *last = NULL;
public:
    void push(int);
    int pop();
    int size();
    void show();
};

int main(){
    int n;
    Queue q1;
    while(true){
        cout << "1. push" << endl << "2. pop" << endl << "3. size" << endl;
        cin >> n;
        if(n == 1){
            cin >> n;
            q1.push(n);
        }else if(n == 2){
            n = q1.pop();
            cout << n << endl;
        }else if(n == 3){
            n = q1.size();
            cout << n << endl;
        }
        q1.show();
    }
    return 0;
}

void Queue::push(int a){
    Item *i1 = new Item;
    if(first == NULL){
        first = i1;
    }else{
        last -> next = i1;
    }
    last = i1;
    i1 -> val = a;
}

int Queue::pop(){
    Item *i1 = first;
    int e = i1 -> val;
    first = i1 -> next;
    delete(i1);
    return e;
}

int Queue::size(){
    if(first == NULL) return 0;
    int n = 1;
    Item *i1 = first;
    for(n; i1 != last; n++){i1 = i1 -> next;}
    return n;
}

void Queue::show(){
    for(Item *i1 = first; i1 != NULL;){
        cout << i1 -> val << " ";
        i1 = i1 -> next;
    }
    cout << endl;
}
