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
        if (head == NULL) {
            return head;
        }
        
        ListNode* cur = head;
        int cnt = 0;
        
        // First, check if there are at least k nodes left in the linked list
        while (cur != NULL && cnt < k) {
            cur = cur->next;
            cnt++;
        }
        
        // If we have k nodes, then we proceed to reverse
        if (cnt == k) {
            cur = head;
            ListNode* prev = NULL;
            ListNode* temp = NULL;
            
            // Reverse k nodes
            for (int i = 0; i < k; i++) {
                temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }
            
            // Now head is the last node in the reversed k group
            // Its next should point to the result of the next k group reversals
            head->next = reverseKGroup(cur, k);
            
            // prev is the new head of the reversed k-group
            return prev;
        } else {
            // If there are less than k nodes left, return head as is (no reversal)
            return head;
        }
    }
};
