class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        
        node(int _key, int _val){
            key = _key;
            val = _val; 
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int, node*> m;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node *delnode){
        node *tempprev = delnode->prev;
        node *tempnext = delnode->next;
        tempprev->next = tempnext;
        tempnext->prev = tempprev;
    }
    
    int get(int key_) {
        if(m.find(key_) != m.end()){
            node *res = m[key_];
            int val = res->val;
            m.erase(key_);
            deletenode(res);
            addnode(res);
            m[key_] = head->next;
            return val;
        }
        
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_) != m.end()){
            node *existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key_, value));
        m[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */