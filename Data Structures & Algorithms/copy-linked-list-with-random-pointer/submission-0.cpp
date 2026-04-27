/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> copy{};
        Node* learner = head;
        while(learner){
            Node* deep_copy= new Node(learner->val);
            //deep_copy.next = learner->next;
            //deep_copy.random = learner->random;
            copy[learner] = deep_copy;
            learner = learner->next;
        }
        //{real:copy, real:copy}
        Node* filler = head;
        while(filler){
            if(!filler->next){
                copy[filler]->next = nullptr;
            }
            else{
                copy[filler]->next = copy[filler->next];
            }
            if(!filler->random){
                copy[filler]->random = nullptr;
            }
            else{
                copy[filler]->random = copy[filler->random];
            }
            
            filler = filler->next;
        }
        return copy[head];
    }
};
