class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int,Node*> m;
    Node* head;
    Node* tail;
    
    LRUCache(int capacity) {
        this->capacity = capacity; 

        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        this->head->next = tail;
        this->tail->prev = head; 
    }

    void insertAtHead(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        else{
            Node* temp = m[key];
            deleteNode(temp);
            insertAtHead(temp);
            return temp->val;
        }
    };
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* temp = m[key];
            deleteNode(temp);
            insertAtHead(temp);
            temp->val = value;
            return;
        }
        else{
            if(m.size()==capacity){
                Node* temp = tail->prev;
                deleteNode(temp);
                m.erase(temp->key);
                delete temp;

                Node* temp2 = new Node(key,value);
                insertAtHead(temp2);
                m[key] = temp2;
                return;
            }
            else{
                Node* temp2 = new Node(key,value);
                insertAtHead(temp2);
                m[key]=temp2;
                return;
            }
        }
    };
};
