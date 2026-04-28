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
        while(l1 || l2){
            int sum = 0;
            if(!l1){
                sum = 0 + l2->val + carry; //
                l2 = l2->next;
            }
            else if(!l2){
                sum = l1->val + 0 + carry; // 10, 10, 10
                l1 = l1->next;
            }
            else{
                sum = l1->val + l2->val + carry; // 18, 19, 19, 19
                l1 = l1->next;
                l2 = l2->next;
            }
            int val = sum%10; // 8, 9, 9, 9, 0, 0, 0
            curr->next = new ListNode(val); // 8, 9, 9, 9, 0, 0,0
            carry = sum/ 10; // 1, 1, 1, 1, 1, 1, 1
            curr = curr->next;
        }
        if(carry){
            curr->next = new ListNode(carry);
        }
        return lead->next;
    }
};
