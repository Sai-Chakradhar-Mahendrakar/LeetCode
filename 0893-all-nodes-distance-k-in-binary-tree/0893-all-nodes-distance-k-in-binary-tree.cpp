/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// x + 1 + 1 + D = k -> x = k - D - 2
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        printNodeAtDistanceK(root, target, k);
        return res;
    }

private:
    vector<int> res;

    void printAtLevelK(TreeNode* root, int k) {
        if (root == NULL) {
            return;
        }
        if (k == 0) {
            res.push_back(root->val);
            return;
        }
        printAtLevelK(root->left, k - 1);
        printAtLevelK(root->right, k - 1);
    }

    int printNodeAtDistanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == NULL) {
            return -1;
        }

        if (root == target) {
            printAtLevelK(root, k);
            return 0;
        }

        int DL = printNodeAtDistanceK(root->left, target, k);
        if (DL != -1) {
            if (DL + 1 == k) {
                res.push_back(root->val);
            } else {
                printAtLevelK(root->right, k - DL - 2);
            }
            return DL + 1;
        }

        int DR = printNodeAtDistanceK(root->right, target, k);
        if (DR != -1) {
            if (DR + 1 == k) {
                res.push_back(root->val);
            } else {
                printAtLevelK(root->left, k - DR - 2);
            }
            return DR + 1;
        }

        return -1;
    }
};