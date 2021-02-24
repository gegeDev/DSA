#include <iostream>
using namespace std;

class List{
    struct Item{int val; Item *next; Item *prev;};
    Item elem;
    Item *first = NULL;
    Item *last = NULL;
public:
    int on(unsigned long); // done
    void push_front(int); // done
    void push_back(int); // done
    int pop_front(); // done
    int pop_back(); // done
    int size(); // done
    bool empty(); // done
    void remove(unsigned long); // done
};

// --------------MAIN---------------
int main(){
    int n;
    List l1;
    while(true){
        cout << "1. push_back" << endl << "2. push_front" << endl << "3. pop_back" << endl << "4. pop_front" << endl << "5. on" << endl << "6. size" << endl << "7. remove" << endl;
        cin >> n;
        if(n == 1){
            cin >> n;
            l1.push_back(n);
        }else if(n == 2){
            cin >> n;
            l1.push_front(n);
        }else if(n == 3){
            n = l1.pop_back();
            cout << n << endl;
        }else if(n == 4){
            n = l1.pop_front();
            cout << n << endl;
        }else if(n == 5){
            cin >> n;
            cout << l1.on(n) << endl;
        }else if(n == 6){
            cout << l1.size() << endl;
        }else if(n == 7){
            cin >> n;
            l1.remove(n);
        }
        for(int i = 0; i < l1.size(); i++){
            cout << l1.on(i) << " ";
        }
        cout << endl;
    }
                
    return 0;
}
// front -> [a,b,c,d,e,f] <- back
int List::on(unsigned long a){
    Item *temp = first;
    for(int i = 0; i < a; i++){
        temp = temp -> next;
    }
    return temp -> val;
}

void List::push_front(int a){
    Item *i1 = new Item;
    i1 -> val = a;
    i1 -> next = first;
    i1 -> prev = last;
    if(last != NULL){
        Item *i2 = last;
        i2 -> next = i1;
        i2 = first;
        i2 -> prev = i1;
    }else if(last == NULL){
        last = i1;
        i1 -> next = i1;
        i1 -> prev = i1;
    }
    first = i1;
}

void List::push_back(int a){
    Item *i1 = new Item;
    i1 -> val = a;
    i1 -> next = first;
    i1 -> prev = last;
    if(first != NULL){
        Item *i2 = last;
        i2 -> next = i1;
        i2 = first;
        i2 -> prev = i1;
    }else if(first == NULL){
        first = i1;
        i1 -> next = i1;
        i1 -> prev = i1;
    }
    last = i1;
}

int List::pop_front(){
    Item *i1 = first;
    if(first == last){
        first == NULL;
        last == NULL;
    }else if(first != last){
        Item *i2 = i1 -> next;
        i2 -> prev = last;
        first = i2;
        i2 = last;
        i2 -> next = first;
    }
    int e = i1 -> val;
    delete(i1);
    return e;
}

int List::pop_back(){
    Item *i1 = last;
    if(first == last){
        first = NULL;
        last = NULL;
    }else if(first != last){
        Item *i2 = i1 -> prev;
        i2 -> next = first;
        last = i2;
        i2 = first;
        i2 -> prev = last;
    }
    int e = i1 -> val;
    delete(i1);
    return e;
}

bool List::empty(){return first == NULL && last == NULL;}

int List::size(){
    if(first == NULL){return 0;}
    Item *temp = first;
    int i;
    for(i = 1; temp -> next != first; i++){
        temp = temp -> next;
    }
    return i;
}

void List::remove(unsigned long a){
    Item *i1 = first;
    for(int i = 0; i < a; i++){
        i1 = i1 -> next;
    }
    if(first == last){
        first = NULL;
        last = NULL;
    }else{
        Item *i2 = i1 -> prev;
        Item *i3 = i1 -> next;
        i2 -> next = i3;
        i3 -> prev = i2;
        if(first == i1){first = i3;}
        else if(last == i1){last = i2;}
    }
    delete(i1);
}
