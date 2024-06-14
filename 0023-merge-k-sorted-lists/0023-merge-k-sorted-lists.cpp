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
    ListNode* MergeLists(ListNode* a, ListNode* b){
        if(a==NULL){
            return b;
        }

        if(b==NULL){
            return a;
        }

        ListNode* c = NULL;
        if(a->val<=b->val){
            c = a;
            c->next = MergeLists(a->next,b);
        }else{
            c = b;
            c->next = MergeLists(a,b->next);
        }

        return c;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0){
            return NULL;
        }

        while(n>1){
            for(int i=0;i<n/2;i++){
                lists[i] = MergeLists(lists[i],lists[n-i-1]);
            }
            n = (n+1)/2;
        }

        return lists.front();
    }
};