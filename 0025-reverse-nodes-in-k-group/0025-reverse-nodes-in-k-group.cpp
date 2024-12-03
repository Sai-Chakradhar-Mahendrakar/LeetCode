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
        if (head == NULL || k == 1) {
            return head;
        }

        int cnt = 0;
        ListNode* node = head;
        while (node != NULL && cnt < k) {
            node = node->next;
            cnt++;
        }

        if (cnt < k) {
            return head;
        }

        cnt = 0;
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* temp;

        while (cur != NULL and cnt < k) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
            cnt++;
        }

        if (cur != NULL) {
            head->next = reverseKGroup(cur, k);
        }

        return prev;
    }
};