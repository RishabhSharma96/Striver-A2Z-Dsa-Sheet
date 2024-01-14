class Node{
public: 
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val){
        this->key = key;
        this->val = val;
    }
};

class LRUCache {
public:

    Node* mru = new Node(-1, -1);
    Node* lru = new Node(-1, -1);
    unordered_map<int, Node*> m;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
        mru -> next = lru;
        lru -> prev = mru;
    }

    void addNode(Node* newnode){
        Node* temp = mru -> next;
        newnode -> next = temp;
        newnode -> prev = mru;
        mru -> next = newnode;
        temp -> prev = newnode;
    }

    void deleteNode(Node* delnode){
        Node* prevv = delnode -> prev;
        Node* nextt = delnode -> next;
        delnode -> prev -> next = delnode -> next;
        delnode -> next -> prev = delnode -> prev;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            Node* resNode = m[key];
            int ans = resNode -> val;

            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            m[key] = mru -> next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }

        if(m.size() == cap){
            m.erase(lru -> prev -> key);
            deleteNode(lru -> prev);
        }

        addNode(new Node(key, value));
        m[key] = mru -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
*/