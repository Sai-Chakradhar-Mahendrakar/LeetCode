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
       ListNode* res = new ListNode();
       ListNode* cur = res;
       int carry = 0;

       while(l1!=NULL || l2!=NULL){
        int n1 = (l1!=NULL) ? l1->val : 0;
        int n2 = (l2!=NULL) ? l2->val : 0;

        int sum = n1+n2+carry;
        carry = sum/10;

        cur->next = new ListNode(sum%10);
        cur = cur->next;

        if(l1!=NULL){
            l1 = l1->next;
        }

        if(l2!=NULL){
            l2 = l2->next;
        }
       }

       if(carry==1){
        cur->next = new ListNode(1);
       }

       return res->next;
    }
};