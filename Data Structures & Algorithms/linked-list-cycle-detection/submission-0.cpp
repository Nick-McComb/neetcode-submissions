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
    bool hasCycle(ListNode* head) {
        /*
        I think firstly check if head is null and if so return false
        create a slow and fast pointer
        fast pointer is equal to head->next
        loop thru while fast and slow are not null
        if(slow == fast) return true
        set fast = to fast->next->next
        set slow to -> slow->next
        if the loop breaks return false
        */
        if(!head){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow && fast && fast->next){
            if(slow == fast){
                return true;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};
