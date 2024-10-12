/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int post(TreeNode* root, int& maxRes){
        if(root==NULL){
            return 0;
        }

        int left = max(post(root->left,maxRes),0);
        int right = max(post(root->right,maxRes),0);

        int curRes = root->val+left+right;
        maxRes = max(maxRes, curRes);

        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxRes = INT_MIN;
        post(root, maxRes);
        return maxRes;
    }
};