#include <iostream>
#include "Double-linked_list_template.hpp"

using namespace std;

void removeDuplis(List<char> *list){
    Node <char> *i;
    Node <char> *j;
    Node <char> *aux;
    if(list -> isEmpty()) return;
    i = list -> First();

    while(i != nullptr){
        j = i -> next;
        while(j != nullptr){
            if(j -> payload == i -> payload){
                aux = j;
                list -> next(j);
                list -> remove(aux);
                continue;
            }
            list -> next(j);
        }
        list -> next(i);
    }
}


int main(){
    List<char> list;

    list.postInsert('a', nullptr);
    list.postInsert('b', nullptr);
    list.postInsert('z', nullptr);
    list.postInsert('a', nullptr);
    list.postInsert('z', nullptr);

    cout<< "------Original list------" <<endl;
    Node<char>* currentElement = list.First();

    while(currentElement != nullptr){
        cout<< "[" << *list.get(currentElement) << "] -> ";
        list.next(currentElement);
    }
    cout<< "NULL" <<endl;

    removeDuplis(&list);

    cout<< "------Changed list------" <<endl;
    Node<char>* index = list.First();

    while(index != nullptr){
        cout<< "[" << *list.get(index) << "] -> ";
        list.next(index);
    }
    cout<< "NULL" <<endl;

    return 0;
}
