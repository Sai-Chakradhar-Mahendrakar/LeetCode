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
    void dfs(TreeNode* root, int maxOf, int& res){
        if(root==NULL){
            return;
        }

        if(root->val >= maxOf){
            res++;
        }

        dfs(root->left, max(maxOf,root->val), res);
        dfs(root->right, max(maxOf,root->val), res);
    }

    
    int goodNodes(TreeNode* root) {
        int res=0;
        dfs(root, root->val, res);
        return res;
    }
};