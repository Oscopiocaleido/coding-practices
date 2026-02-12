
template <typename T>

class Node{
    public:
    T payload;
    Node <T> *next;
    Node <T> *prev;

    Node(T v){
        payload = v;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>

class List {
    private:
    Node <T> *_first;
    Node <T> *_last;

    public:
    List(){
        _first = _last = nullptr;
    }
    ~List(){
        while(!isEmpty()){
            remove(First());
        }
    }
    Node <T> *First(){
        return _first;
    }
    Node <T> *Last(){
        return _last;
    }
    bool isEmpty(){
        return First() == nullptr;
    }
    void next(Node <T> *&i){
        if(i == nullptr) return;
        i = i -> next;
    }
    void previus(Node <T> *&i){
        if(i == nullptr) return;
        i = i -> prev;
    }
    T* get(Node <T> *i){
        if(i == nullptr) return nullptr;
        return &i -> payload;
    }
    void remove(Node <T> *i){
        if(i == nullptr) return;
        if(i -> prev != nullptr) i -> prev -> next = i -> next;
        if(i -> next != nullptr) i -> next -> prev = i -> prev;
        if(i == First()) _first = i -> next;
        if(i == Last()) _last = i -> prev;
        delete i;
    }
    void preInsert(T v, Node <T> *pos){
        Node <T> *newNode = new Node(v);
        if(isEmpty()){
            _first = _last = newNode;
            return;
        }
        if(pos == nullptr) pos = First();
        newNode -> next = pos;
        newNode -> prev = pos -> prev;
        newNode -> next -> prev = newNode;
        if(pos == First()) _first = newNode;
        else
            newNode -> prev -> next = newNode;
    }
    void postInsert(T v, Node <T> *pos){
        Node <T> *newNode = new Node(v);
        if(isEmpty()){
            _first = _last = newNode;
            return;
        }
        if(pos == nullptr) pos = Last();
        newNode -> prev = pos;
        newNode -> next = pos -> next;
        newNode -> prev -> next = newNode;
        if(pos == Last()) _last = newNode;
        else
            newNode -> next -> prev = newNode;
    }
};
