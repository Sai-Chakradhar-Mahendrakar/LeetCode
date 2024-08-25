/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0;
        int lenB=0;

        for(auto temp=headA;temp;temp=temp->next){
            lenA++;
        }
        for(auto temp=headB;temp;temp=temp->next){
            lenB++;
        }

        while(lenA>lenB){
            headA=headA->next;
            lenA--;
        }

        while(lenA<lenB){
            headB=headB->next;
            lenB--;
        }

        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }

        return headA;
    }
};