#include <iostream>
#include "Double-linked_list_template.hpp"

using namespace std;

int sum(List<int> &list){
    Node<int> *carry = list.First();
    int r = 0;
    while(carry != nullptr){
        r += carry->payload;
        list.next(carry);
    }
    return r;
}

int main(){
    List<int> list;

    list.postInsert(2, nullptr);
    list.postInsert(4, nullptr);
    list.postInsert(6, nullptr);
    list.postInsert(8, nullptr);
    list.postInsert(10, nullptr);

    cout<< "-----Lista-----" <<endl;
    Node<int> *index = list.First();

    while (index != nullptr){
        cout<< "[" << *list.get(index) << "] -> ";
        list.next(index);
    }
    cout<< "NULL" <<endl;

    cout<< "-----Suma de los elementos de la lista-----" <<endl;
    cout<< sum(list) <<endl;

    return 0;
}
