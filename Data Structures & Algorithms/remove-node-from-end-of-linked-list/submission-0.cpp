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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        loop thru get the size of the list
        if size = 1 return nullptr
        if n = size return head->next

        do size-n thats the index to remove
        start from 0 < size-n in a for loop
        then set that element->next = element->next->next
        */


        ListNode* learner = head;
        int size = 0;
        while(learner){
            learner = learner->next;
            size ++;
        }
        if(size == n){
            return head->next;
        }
        int index = size-n; //index directly before
        ListNode* clone = head;
        for(int i = 1; i<index; i++){
            clone= clone->next;
        }
        clone->next = clone->next->next;
        return head;
    }
};
