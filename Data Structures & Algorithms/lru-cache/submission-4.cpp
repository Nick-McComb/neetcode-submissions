class Node{
public:
    int val;
    int key;
    Node * prev = nullptr;
    Node * next = nullptr;

    Node(){}
    Node(int v) : val(v){}
    Node(int v, int k) : val(v), key(k){}
    Node(int v, Node* n) : val(v), next(n){}

};

class LRUCache {
public:
    int size =0;
    int capacity; //2
    //list<Node*> dll{};
    unordered_map<int, Node*> seen{}; 
    Node* dummy = new Node(-1);
    Node* tail = dummy;
    LRUCache(int c): capacity(c) {
        //dll.push_back(&dummy);
    }
    
    int get(int key) {
        if(seen.contains(key)){ //found the key in the map
            Node* key_node = seen[key]; //gets the node associated with that key
            if(key_node == tail){
                return key_node->val;
            }
            //removes key_node from the list
            key_node->prev->next = key_node->next;
            key_node->next->prev = key_node->prev;
            //puts it at the end of the list
            tail->next = key_node;
            key_node->prev =tail;
            key_node->next = nullptr;
            tail = key_node;

            return key_node->val;
        }
        return -1;
    }
    // {2:1}
    // 
    void put(int key, int value) {
        if(seen.contains(key)){
            Node * key_node = seen[key];
            //removes the node from the list
            if(tail == key_node){
                key_node->val = value;
                return;
            }
            key_node->prev->next = key_node->next;
            key_node->next->prev = key_node->prev;
            //puts it at the end of the list
            tail->next = key_node;
            key_node->prev =tail;
            key_node->next = nullptr;
            tail = key_node;
            //updates it's value
            key_node->val = value;
        }
        else{
            while(size >= capacity){
                //remove the lru element from the beggining of the dll
                int k = dummy->next->key; // -1 -> (2,1)
                dummy->next = dummy->next->next; //
                if(dummy->next){
                    dummy->next->prev = dummy;
                }
                size--;
                seen.erase(k);
            }
            //insert new element
            Node* new_node = new Node(value, key);
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
            seen[key] = new_node;
            size++;
        }
    }
    //deconstructor (memory things)
    
    ~LRUCache(){
        while(dummy){
            Node* prev = dummy;
            dummy = dummy->next;
            delete prev;
        }
    }
};
