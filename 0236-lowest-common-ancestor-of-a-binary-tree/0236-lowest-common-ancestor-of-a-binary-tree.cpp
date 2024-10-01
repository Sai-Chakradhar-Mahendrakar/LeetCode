/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        if(left && left!=p && left!=q){
            return left; // found in left subtree
        }

        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right){
            return root;  // Present in different subtree;
        }

        return left ? left:right; // return non null value
    }
};