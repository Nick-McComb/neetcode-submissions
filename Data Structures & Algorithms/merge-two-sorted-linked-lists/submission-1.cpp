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
/*
create a dummy node, before the entire list
then set curr to be that dummy node
loop thru while both the lists exist
check if list1 < list2 if so set curr.next to that list
then got to the next element of that list
do the opposite of the conditional if it hits the else
go to curr.next
then see which list if any still have elements and add it to the end of the curr list
then return dummy.next, which dummy is befoe the list, so .next is the head of the list
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        

        //ListNode* head = min(list1, list2, [](ListNode* l1, ListNode* l2){return l1->val < l2->val;});
        while(list1 && list2){
            if(list1->val < list2->val){
                curr->next = list1;
                list1 = list1->next;
            }
            else{
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if(list1){
            curr->next = list1;
        }
        else{
            curr->next = list2;
        }
        return dummy.next;
    }
};
