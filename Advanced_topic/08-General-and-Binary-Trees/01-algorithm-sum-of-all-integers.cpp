#include <iostream>
#include "Binary-search-tree-template.hpp"

using namespace std;

template <typename T>

int sumAllIntegers(Node<T> *i, int currentLevel, int minLevel, int maxLevel){
    if(i == nullptr) return 0;
    if(currentLevel > maxLevel) return 0;

    int result = 0;

    if(currentLevel >= minLevel && currentLevel <= maxLevel){
        result += i -> p;
    }

    result += sumAllIntegers(i -> l_child, currentLevel + 1, minLevel, maxLevel);
    result += sumAllIntegers(i -> r_child, currentLevel + 1, minLevel, maxLevel);

    return result;
}

int main(){
    BST <int> treeBin;

    treeBin.insert(2);
    treeBin.insert(1);
    treeBin.insert(4);
    treeBin.insert(3);
    treeBin.insert(5);

    /*
      2
     / \
    1   4
       / \
      3   5
   */

    cout<< "Result: " << sumAllIntegers(treeBin.getRoot(), 0, 1, 2) <<endl;
    return 0;
}
