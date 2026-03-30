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
        int count = 1;
        ListNode* temp = head;
        while(temp->next){
            temp=temp->next;
            count++;
        }

        temp = head;
        for(int i=1; i<count/2; i++){
            temp=temp->next;
        }

        ListNode* temp2 = temp->next;
        temp->next = NULL;

        ListNode* prev = NULL;
        ListNode* curr = temp2;
        ListNode* forward;

        while(curr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        ListNode* t1 = head;
        ListNode* t2 = prev;
        ListNode* t = new ListNode(-1);

        while(t1 && t2){
            t->next = t1;
            t1 = t1->next;
            t = t->next;
            t->next = t2;
            t2 = t2->next;
            t = t->next;
        }

        return;
    }
};
