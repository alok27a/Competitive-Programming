class Node{
public:
    int key, val;
    Node* prev;
    Node* next;
    Node(int _key, int _val)
    {
        key = _key;
        val = _val; 
    }
};

class LRUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newnode)
    {
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(Node* delnode)
    {
        Node* p = delnode->prev;
        Node* n = delnode->next;
        p->next = n;
        n->prev = p;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* n = mp[key];
        int val = n->val;
        
        // Move the node to the front (most recently used)
        deleteNode(n);
        addNode(n);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            // Node exists, update value and move to front
            Node* n = mp[key];
            mp.erase(key);
            deleteNode(n);
        }
        if(mp.size() == cap)
        {
            // Remove least recently used node (tail->prev)
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        // Insert new node
        Node* newnode = new Node(key, value);
        addNode(newnode);
        mp[key] = newnode;
    }
};
