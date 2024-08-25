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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL or k==0){
            return head;
        }

        int len=1;
        ListNode* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
            len++;
        }

        k=k%len;
        int c=1;
        ListNode* curr=head;

        if(k==0){
            return head;
        }

        while(c<len-k){
            curr=curr->next;
            c++;
        }

        tail->next=head;
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};