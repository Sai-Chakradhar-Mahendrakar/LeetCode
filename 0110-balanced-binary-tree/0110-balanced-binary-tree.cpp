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
    bool isBalanced(TreeNode* root) {
        pair<int, bool> p = heightIsBalanced(root);
        return p.second;
    }
private:
    pair<int, bool> heightIsBalanced(TreeNode* root){
        if(root==NULL){
            return {0, true};
        }

        pair<int,bool>left,right;
        left=heightIsBalanced(root->left);
        right=heightIsBalanced(root->right);

        int h = 1+max(left.first, right.first);
        if(abs(left.first-right.first)<=1 && left.second && right.second){
            return {h, true};
        }

        return {h, false};
    }
};