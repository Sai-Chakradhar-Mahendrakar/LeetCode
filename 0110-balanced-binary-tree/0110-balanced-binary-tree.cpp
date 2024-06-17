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
    pair<int,bool> isHeightBalanced(TreeNode* root){
        if(root==NULL){
            return {0,true};
        }
        pair<int,bool>p,left,right;
        left = isHeightBalanced(root->left);
        right = isHeightBalanced(root->right);

        int height = max(left.first,right.first)+1;
        if(abs(left.first-right.first)<=1 and left.second and right.second){
            return {height,true};
        }

        return {height,false};
    }

    bool isBalanced(TreeNode* root) {
        auto p = isHeightBalanced(root);
        return p.second;
    }
};