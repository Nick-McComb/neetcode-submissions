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
        */

        vector<ListNode*> learned{};
        ListNode* learner = head;
        while(learner){
            learned.push_back(learner);
            learner = learner->next;
        }

        int i = 0;
        int j = learned.size() -1;

        while(i<j){
            learned[i]->next = learned[j];
            i++;
            if(i>=j){
                break;
            }
            learned[j]->next = learned[i];
            j--;
        }
        learned[i]->next = nullptr;


    }
};
