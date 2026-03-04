template <typename T>

class Node{
    public:
    T p;
    Node <T>* l_child;
    Node <T>* r_child;
    Node(T v){
        p = v;
        l_child = r_child = nullptr;
    }
};

template <typename T>

class BST{
    private:
    Node <T> *root;
    void insert(Node <T> *&i, T v){
        if(i == nullptr){
            i = new Node(v);
            return;
        }
        if(v < i -> p){
            insert(i -> l_child, v);
        }else{
            insert(i -> r_child, v);
        }
    }
    bool find(Node <T> *&i, T v){
        if(i == nullptr) return false;
        if(i -> p == v) return true;
        if(v < i -> p){
            return find(i -> l_child, v);
        }
        return find(i -> r_child, v);
    }
    public:
    BST(){root = nullptr;}
    ~BST(){}
    void insert(T v){insert(root, v);}
    bool find(T v){return find(root, v);}
    Node<T>* getRoot(){
        return root;
    }
};
