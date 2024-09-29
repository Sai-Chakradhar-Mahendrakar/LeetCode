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
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int>p = calDiameter(root);
        return p.second;
    }
private:
    pair<int, int> calDiameter(TreeNode* root){
        if(root==NULL){
            return {0, 0};
        }

        pair<int, int> left, right;
        left = calDiameter(root->left);
        right = calDiameter(root->right);

        int h = max(left.first, right.first)+1;
        int d1 = left.first+right.first;
        int d2 = left.second;
        int d3 = right.second;
        int d = max(d1, max(d2, d3));

        return {h, d};
    }
};