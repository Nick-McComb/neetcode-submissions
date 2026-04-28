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
        ListNode t(0);
        ListNode* lead= &t;
        ListNode* curr = lead;
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
        return lead->next;
    }
};
