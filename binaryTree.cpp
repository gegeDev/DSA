/* ------------------------------------
 * everything works perfectly fine
 * there is no way to find duplicates
 * there is no way to balance a tree
-------------------------------------*/

#include <iostream>
using namespace std;
class Tree{
    struct Item{int val; Item *left = NULL; Item *right = NULL;};
    Item *root = NULL;
public:
    void insert(int);
    bool search(int);
    void show();
};
int main(){
    Tree t1;
    int n;
    while(true){
        cout << "1. insert" << endl << "2. search" << endl;
        cin >> n;
        if(n == 1){
            cin >> n;
            t1.insert(n);
        }else if(n == 2){
            cin >> n;
            cout << t1.search(n) << endl;
        }
    } 
    return 0;
}
void Tree::insert(int a){
    Item *i1 = new Item;
    if(root == NULL){
        root = i1;
    }else{
        Item *i2 = root;
        while(i2 != NULL){
            if(a > i2 -> val){
                if(i2 -> right == NULL){
                    i2 -> right = i1;
                    i2 = NULL;
                }else{
                    i2 = i2 -> right;
                }
            }else{
                if(i2 -> left == NULL){
                    i2 -> left = i1;
                    i2 = NULL;
                }else{
                    i2 = i2 -> left;
                }
            }
        }
    }
    i1 -> val = a;
}

bool Tree::search(int a){
    Item *i1 = root;
    while(i1 != NULL){
        if(i1 -> val == a){return true;}
        if(a > i1 -> val){
            cout << "right" << endl;
            i1 = i1 -> right;
        }else{
            cout << "left" << endl;
            i1 = i1 -> left;
        }
    }
    return false;
}
