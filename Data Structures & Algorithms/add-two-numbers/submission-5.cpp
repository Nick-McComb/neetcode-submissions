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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //5->6->4
        //2->4->3->3

        //9->9->9->9->9->9->9
        //9->9->9->9

        /*
        create curr, which is a dummy node behind head to start
        loop thru while either l1 or l2 or carry exsists
        sum the value of l1 + l2 + carry if they exsist
        then modulo the sum by 10 to get the ones place
        create a new node with the ones place set curr->next to it
        then set the carry to be the sum/10 (this is what needs to be added to the next value)
        then go to curr = curr->next 
        and l1 = l1->next
        and l2 = l2 ->next
        if these both exist ofc
        then return dummy->next;
        */
        ListNode t(0);
        ListNode* dummy= &t;
        ListNode* curr = dummy;
        int carry = 0;
        while(l1 || l2 || carry){
            
            int l1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;
            
            int sum = l1_val + l2_val + carry;
            int val = sum%10; // 8, 9, 9, 9, 0, 0, 0
            curr->next = new ListNode(val); // 8, 9, 9, 9, 0, 0,0
            carry = sum/ 10; // 1, 1, 1, 1, 1, 1, 1
            curr = curr->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            
        }
        return dummy->next;
    }
};
