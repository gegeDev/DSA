#include <iostream>
using namespace std;
class BST{
protected:
    struct item{int val; item *left = NULL; item *right = NULL;};
    item *top;
    int height;
    item *insert(int a, item* target){
        static int h;
        if(target == NULL){
            item *n = new item;
            n -> val = a;
            top = n;
            return n;
        }else if(a < target -> val){
            if(target -> left == NULL){
                item *n = new item;
                n -> val = a;
                target -> left = n;
                if(++h > height) height = h;
                h = 0;
                return n;
            }else{
                h++;
                return insert(a, target -> left);
            }
        }else{
            if(target -> right == NULL){
                item *n = new item;
                n -> val = a;
                target ->right = n;
                if(++h > height) height = h;
                h = 0;
                return n;
            }else{
                h++;
                return insert(a, target -> right);
            }
        }
    }
    void readPreOrder(item *target){
        if(target == NULL) return;
        cout << target -> val << endl;
        readPreOrder(target -> left);
        readPreOrder(target -> right);
    }
    void readPostOrder(item *target){
        if(target == NULL) return;
        readPostOrder(target -> left);
        readPostOrder(target -> right);
        cout << target -> val << endl;
    }
    void readInOrder(item *target){
        if(target == NULL) return;
        readInOrder(target -> left);
        cout << target -> val << endl;
        readInOrder(target -> right);
    }
    item *findFather(int n, item *target){
        if(target -> val > n){
            if(target -> left != NULL){
                if(target -> left -> val == n) return target;
                else return findFather(n, target -> left);
            }
        }else{
            if(target -> right != NULL){
                if(target -> right -> val == n) return target;
                else return findFather(n, target -> right);
            }
        }
        return NULL;
    }
    item *find(int n, item *target){ // Funkcja znajdująca element o podanej wartości i zwracająca wskaźnik na ten element
        if(target == NULL) return NULL;
        else if(target -> val == n) return target;
        else if(target -> val > n) return find(n, target -> left);
        return find(n, target -> right);
    }
    void deletePostOrder(item *target){ // Rekurencyjne usunięcie wszystkich elementów w kolejności postOrder
        if(target == NULL) return;
        deletePostOrder(target -> left);
        deletePostOrder(target -> right);
        cout << target -> val << endl;
        remove(target);
    }
    void remove(item *thrash){
        // Funkcja jest zabezpieczona przed wywołaniem jej dla wskaźnika NULL
        if(!thrash) return;
        item *father = findFather(thrash -> val, top);
        if(thrash -> left == NULL){ // Sytuacja w której usuwana wartość nie ma lewego potomka, ten if wykona się również jeżeli drzewo składa się z tylko jednego elementu
            if(father){ // Jeśli usuwany element ma ojca, musimy zmienić odpowiedni wskaźnik ojca na element na prawo od usuwanego elementu
                if(thrash == father -> left)  father -> left = thrash -> right;
                else father -> right = thrash -> right;
            } // Jeśli wskaźnik nie ma ojca, musimy zmienić wskaźnik na wierzchołek drzewa
            else top = thrash -> right;
            delete(thrash);
        }else if(thrash -> right == NULL){
            if(father){
                if(thrash == father -> left) father -> left = thrash -> left;
                else father -> right = thrash -> left;
            }
            else top = thrash -> left;
            delete(thrash);
        }else{ // Ten else odpowiada sytuacji w której usuwamy element, który ma lewego i prawego potomka
            if(thrash->val - thrash->left->val > thrash->right->val - thrash->val){
                // To który element zostanie wstawiony w miejsce usuwanego, zależy od tego, który mniej się od niego różni
                item *temp = thrash -> left;
                father = thrash;
                while(temp->right != NULL){
                    father = temp;
                    temp = temp -> right;
                }
                swap(temp -> val, thrash -> val);
                if(father == thrash) father -> left = temp -> left;
                else father -> right = temp -> left;
                delete(temp);
            }else{
                item *temp = thrash -> right;
                father = thrash;
                while(temp -> left != NULL){
                    father = temp;
                    temp = temp -> left;
                }
                swap(temp -> val, thrash -> val);
                if(father == thrash) father -> right = temp -> right;
                else father -> left = temp -> right;
                delete(temp);
            }
        }
    }
    item *rotateRight(item *a){ // Rotacja w prawo
        item *father = findFather(a -> val, top);
        item *b = a -> left;
        if(b && a){
            if(father) father -> right = b;
            else top = b;
            a -> left = b -> right;
            b -> right = a;
        }
        return b;
    }
    item *rotateLeft(item *a){ // Rotacja w lewo
        if(a){
            item *b = a -> right;
            item *father = findFather(a -> val, top);
            if(b){
                a -> right = b -> left;
                b -> left = a;
                if(father) father -> right = b;
                else top = b;
                return b;
            }
        }
        return NULL;
    }
public:
    BST(){ // Konstruktor bezargumentowy, wywołuje się gdy chcemy utworzyć puste drzewo
        top = NULL;
        height = 0;
    }
    BST(int *arr, int n){ // Konstruktor drzewa BST, wstawiający do drzewa po kolei wszystkie elementy wejściowej tablicy
        top = NULL;
        height = 0;
        for(int i = 0; i < n; i++) insert(arr[i], top);
    }
    void balanceDSW(){
        int n = 0;
        item *temp, *target = top;
        // Zamiana drzewa w listę liniową.
        while(target){
            while(target -> left){
                temp = rotateRight(target); // Funkcja rotateRight zwraca element B, który po rotacji jest ojcem elementu target
                if(temp) target = temp; // Dalsze rotacje wykonujemy dla elementów które po rotacji wylądowały wyżej, ponieważ mogą one mieć lewych potomków
            }
            target = target -> right;
            n++; // Liczba n oznacza liczbę węzłów w drzewie.
        }
        int s = 1;
        while(s << 1 < n + 1) s <<= 1;
        s = n + 1 - s;
        target = top;
        for(int i = 0; i < s; i++){
            temp = rotateLeft(target);
            if(temp) target = temp -> right;
        }
        n -= s;
        while(n > 1){

            n >>= 1;
            target = top;
            for(int i = 0; i < n; i++){
                temp = rotateLeft(target);
                target = temp -> right;
            }
        }
    }
    void remove(int n){ // Przeładowana funkcja remove, nie wymaga podawania wskaźnika na odpowiedni element
        item *target = find(n, top);
        if(target) remove(target);
        else cout << "Podany element nie należy do drzewa" << endl;
    }
    // Przeładowane funkcje wypisujące i usuwające drzewo, nie wymagają podawania elementu początkowego
    void readPreOrder(){readPreOrder(top);}
    void readPostOrder(){readPostOrder(top);}
    void readInOrder(){readInOrder(top);}
    void deletePostOrder(){deletePostOrder(top);}
    int findLowest(){
        // Najmniejsza wartość w drzewie to ta, do której dochodzimy przez przechodzenie jedynie w lewo
        item *temp = top;
        int len = 0;
        if(temp){
            while(temp -> left != NULL){
                temp = temp -> left;
                len++;
            }
            if(length) return len;
            return temp -> val;
        }
        cout << "Drzewo jest puste" << endl;
        return 0;
    }
    int findHighest(){
        // Wartość największą w drzewie znajdujemy przez przechodzenie w prawo, dopóki nie napotkamy elementu, który nie ma prawego potomka. Taki element jest największy w drzewie.
        item *temp = top;
        int len = 0;
        if(temp){
            while(temp -> right != NULL){
                temp = temp -> right;
                len++;
            }
            return temp -> val;
        }
        cout << "Drzewo jest puste" << endl;
        return 0;
    }
};

class AVL : public BST{
    /* Klasa AVL dziedziczy z BST i stanowi takie samo drzewo binarne
     * Różnicą jest to, że konstruktor klasy AVL automatycznie tworzy drzewo zrównoważone metodą połowienia binarnego
     * Wszystkie funkcjonalności drzewa BST działają w drzewie buildAVL
     */

    void buildAVL(int *arr, int b, int e, item *&target){ // Funkcja buildAVL działa w przypadku występowania duplikatów w tablicy wejściowej
        if(e==b) return;
        target = new item; // target jest referencją wskaźnika na miejsce w którym należy wstawić nową liczbę. Dzięki temu podejściu drzewo AVL jest zrównoważone nawet jeśli w danych występują duplikaty.
        target -> val = arr[(b+e) / 2];
        // Rekurencyjne wstawienie odpowiednich elementów na prawo i na lewo od obiektu na który wskazuje target
        buildAVL(arr, b, (b+e) / 2, target -> left);
        buildAVL(arr, (b+e) / 2 + 1, e, target -> right);
    }
public:
    AVL(int *arr, int b, int e){
        buildAVL(arr, b, e, top);
    }

};
