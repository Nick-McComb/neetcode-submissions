/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        /*
        vector approach
        store all items in vector
        get pointer to end of vector and front
        set the start pointer -> next equal to the end pointer
        then increment i
        if i>=j break, because this would be a duplicate value
        if not set the end pointer(j)->next equal to value at i
        then once loop breaks set either point to -> next to nullptr so its not infinite loop
        */

        // vector<ListNode*> learned{};
        // ListNode* learner = head;
        // while(learner){
        //     learned.push_back(learner);
        //     learner = learner->next;
        // }

        // int i = 0;
        // int j = learned.size() -1;

        // while(i<j){
        //     learned[i]->next = learned[j];
        //     i++;
        //     if(i>=j){
        //         break;
        //     }
        //     learned[j]->next = learned[i];
        //     j--;
        // }
        // learned[i]->next = nullptr;

        /*
            loop thru the ll and get the length
            with the length get the middle value
            with the middle value loop until at the middle node
            from the middle node reverse the ll
            then iterate thru both lists and follow the every other pattern

        */

        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //5,6,8] rev this for example
        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr;
        while(second){
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        ListNode* h2 = prev;
        ListNode* h1 = head;
        //[2,4]
        //[8,6,5]
        while(h2){
            ListNode* h1_next = h1->next; //nullptr
            ListNode *h2_next = h2->next;
            h1->next = h2;
            h2->next = h1_next;
            h1= h1_next;
            h2 = h2_next;
        }
    }
};
