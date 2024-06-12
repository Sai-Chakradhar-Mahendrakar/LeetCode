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
    
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* temp;
        
        while(cur!=NULL){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        
        return prev;
    }
    
    void merge(ListNode* a, ListNode* b){
        while (a != NULL and b != NULL) {
            ListNode* aNext = a->next;
            ListNode* bNext = b->next;
            
            a->next = b;
            if (aNext == NULL) break;
            
            b->next = aNext;
            a = aNext;
            b = bNext;
        }
    }
    
    void reorderList(ListNode* head) {
        if(head->next==NULL){
            return;
        }
        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next=NULL;
        
        ListNode* l1 = head;
        ListNode* l2 = reverse(slow);
        
        merge(l1,l2);
    }
};