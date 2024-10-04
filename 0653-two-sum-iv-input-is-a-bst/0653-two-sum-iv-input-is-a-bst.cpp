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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> mp;
        return helper(root, k, mp);
    }
private:
    bool helper(TreeNode* root, int k, unordered_set<int>& mp){
        if(root==NULL){
            return false;
        }
        if(mp.find(k-root->val)!=mp.end()){
            return true;
        }
        mp.insert(root->val);
        return helper(root->left, k, mp) || helper(root->right, k, mp);
    }
};