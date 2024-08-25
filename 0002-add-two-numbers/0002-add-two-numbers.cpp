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
// #pragma GCC optimize("O3, unroll-loops")
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        ListNode* res=new ListNode();
        ListNode* curr=res;
        int carry=0;

        while(l1!=NULL || l2!=NULL){
            int n1= (l1!=NULL) ? l1->val : 0;
            int n2= (l2!=NULL) ? l2->val : 0;

            int sum=n1+n2+carry;
            carry=sum/10;

            curr->next=new ListNode(sum%10);
            curr=curr->next;

            if(l1!=NULL){
                l1=l1->next;
            }

            if(l2!=NULL){
                l2=l2->next;
            }
        }

        if(carry==1){
            curr->next=new ListNode(1);
        }
        return res->next;
    }
};