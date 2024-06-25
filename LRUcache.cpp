class LRUCache {
public:
public:
    class Node {
    public:
        int key, value;
        Node* next;
        Node* prev;
        Node(int k, int val) {
            key = k;
            value = val;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(Node* newnode) {
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        if(m.find(key) != m.end()) {
            Node* resnode = m[key];
            int res = resnode->value;
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            Node* existing = m[key];
            m.erase(key);
            deletenode(existing);
        } else if(m.size() == cap) {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */