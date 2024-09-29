class Node{
public:
    int freq;
    Node*prev;
    Node *next;
    unordered_set<string> keys;
    
    Node(int freq): freq(freq),prev(nullptr),next(nullptr){}
};
class AllOne {
    Node* head;
    Node* tail;
    unordered_map<string,Node*> mp;
    void removeNode(Node *node){
        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev=prevNode;
        delete node;
    }
public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if(mp.find(key)!=mp.end()){
            Node *node = mp[key];
            int freq = node->freq;
            node->keys.erase(key);
            Node *nextNode = node->next;
            if(nextNode==tail || nextNode->freq!= freq+1){
                Node *newNode = new Node(freq+1);
                newNode->keys.insert(key);
                newNode->prev = node;
                newNode->next = nextNode;
                node->next=newNode;
                nextNode ->prev = newNode;
                mp[key] = newNode;
            }
            else{
                nextNode->keys.insert(key);
                mp[key]=nextNode;
            }

            if(node->keys.empty()){
                removeNode(node);
            }
        }
        else{
            Node *firstNode = head->next;
            if(firstNode==tail || firstNode->freq>1){
                Node* newNode = new Node(1);
                newNode->keys.insert(key);
                newNode->prev=head;
                newNode->next=firstNode;
                head->next=newNode;
                firstNode->prev=newNode;
                mp[key]=newNode;
            }
            else{
                firstNode->keys.insert(key);
                mp[key] = firstNode;
            }
        }
    }
    
    void dec(string key) {
        if(mp.find(key)==mp.end())
            return;
        Node *node = mp[key];
        node->keys.erase(key);
        int freq = node->freq;

        if(freq==1){
            mp.erase(key);
        }
        else{
            Node *prevNode = node->prev;
            if(prevNode ==head|| prevNode->freq!=freq-1){
                Node *newNode = new Node(freq-1);
                newNode->keys.insert(key);
                newNode->prev=prevNode;
                newNode->next = node;
                prevNode->next=newNode;
                node->prev=newNode;
                mp[key]=newNode;
            }
            else{
                prevNode->keys.insert(key);
                mp[key]=prevNode;
            }
        }
        if(node->keys.empty())
            removeNode(node);
    }
    
    string getMaxKey() {
        if(tail->prev==head)
            return "";
        return *(tail->prev->keys.begin());
    }
    
    string getMinKey() {
        if(head->next==tail) return "";
        return *(head->next->keys.begin());
    }

};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */