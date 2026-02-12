#include <iostream>
#include "Double-linked_list_template.hpp"

using namespace std;

void removeN(List<int*>& list, int sizeArray, int n){
    Node<int*>* index = list.First();

    while(index != nullptr){
        int* array = *list.get(index);

        for(int i = 0; i < sizeArray; i++){
            if(array[i] == n){
                array[i] = -1;
            }
        }
        list.next(index);
    }
}

int main(){
    List<int*> list;

    int* a = new int [4] {1,4,8,9};
    int* b = new int [4] {4,5,0,2};
    int* c = new int [4] {3,6,7,4};

    list.postInsert(a, nullptr);
    list.postInsert(b, nullptr);
    list.postInsert(c, nullptr);

    Node<int*> *currentElement = list.First();

    cout<< "-----Lista original-----" <<endl;

    while(currentElement != nullptr){
        int* array = *list.get(currentElement);
        cout<< "[ ";

        for(int i = 0; i < 4; i++){
            cout<< array[i] << " ";
        }
        cout<< "] -> ";

        list.next(currentElement);
    }
    cout<< "NULL" <<endl;

     Node<int*> *actual = list.First();

    removeN(list, 4, 4);

    cout<< "-----Lista modificada-----" <<endl;

    while(actual != nullptr){
        int* array = *list.get(actual);
        cout<< "[";

        for(int i = 0; i < 4; i++){
            cout<< array[i] << " ";
        }
        cout<< "] -> ";

        list.next(actual);
    }
    cout<< "NULL" <<endl;
}
