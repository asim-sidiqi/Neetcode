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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return NULL;
        if(left==right) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = head;
        ListNode* temp2 = head;
        ListNode* forward;

        for(int i=1; i<left; i++){
            if(curr) curr=curr->next;
            temp=temp->next;
        }

        int count = right-left+1;

        for(int i=0; i<count; i++){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        for(int i=1; i<left-1; i++){
            curr=curr->next;
            temp2=temp2->next;
        }

        temp->next = forward;
        if(left!=1) temp2->next = prev;

        if(left==1) return prev;
        return head;
    }
};