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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0){
            return NULL;
        }

        while(k>1){
            for(int i=0;i<k/2;i++){
                lists[i]=mergeLists(lists[i], lists[k-i-1]);
            }
            k=(k+1)/2;
        }

        return lists.front();
    }
private:
    ListNode* mergeLists(ListNode* a, ListNode* b){
        if(a==NULL){
            return b;
        }

        if(b==NULL){
            return a;
        }

        ListNode* c=NULL;
        if(a->val<b->val){
            c=a;
            c->next=mergeLists(a->next, b);
        }
        else{
            c=b;
            c->next=mergeLists(a,b->next);
        }
        return c;
    }
};