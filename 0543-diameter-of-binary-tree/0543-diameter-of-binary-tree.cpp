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
class HDpair{
    public:
        int ht;
        int dia;
};
class Solution {
public:
    HDpair opt(TreeNode* root){
        HDpair p;
        if(root==NULL){
            p.ht=p.dia=0;
            return p;
        }

        HDpair left = opt(root->left);
        HDpair right = opt(root->right);

        p.ht = max(left.ht,right.ht)+1;
        int d1 = left.ht+right.ht;
        int d2 = left.dia;
        int d3 = right.dia;
        p.dia = max(d1,max(d2,d3));
        return p;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        HDpair p = opt(root);
        return p.dia; 
    }
};