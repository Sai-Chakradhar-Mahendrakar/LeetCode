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
#pragma GCC optimize("O3, unroll-loops")

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }

        ListNode* mid = midPoint(head);
        ListNode* a = head;
        ListNode* b = mid->next;

        mid->next=NULL;
        
        a = sortList(a);
        b = sortList(b);

        return merge(a, b);
    }

private:
    ListNode* midPoint(ListNode* head){
        if(head==NULL or head->next==NULL){
            return head;
        }

        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* a, ListNode* b){
        if(a==NULL){
            return b;
        }

        if(b==NULL){
            return a;
        }

        ListNode* c=NULL;

        if(a->val<b->val){
            c=a;
            c->next=merge(a->next, b);
        }
        else{
            c=b;
            c->next=merge(a, b->next);
        }

        return c;
    }
};