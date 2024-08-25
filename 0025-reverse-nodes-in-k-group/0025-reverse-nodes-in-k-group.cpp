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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==nullptr || k==1){
           return head;
        }
        
        int cnt = 0;
        ListNode* node = head;
        while (node != nullptr && cnt < k) {
            node = node->next;
            cnt++;
        }

        if (cnt < k) {
            return head;
        }
        
        cnt=0;
        ListNode* prev=nullptr;
        ListNode* cur=head;
        ListNode* temp;
        
        while(cur!=nullptr and cnt<k){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
            cnt++;
        }
        
        if(temp!=nullptr){
            head->next=reverseKGroup(temp,k);
        }
        
        return prev;
    }
};