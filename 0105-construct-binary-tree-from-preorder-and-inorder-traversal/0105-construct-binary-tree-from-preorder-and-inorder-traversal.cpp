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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& indx, int i, int j){
        if(i>j){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[indx]);

        int split;
        for(int k=i;k<=j;k++){
            if(preorder[indx]==inorder[k]){
                split=k;
                break;
            }
        }
        indx++;

        root->left = build(preorder, inorder, indx,i,split-1);
        root->right = build(preorder, inorder, indx,split+1,j);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int indx=0;
        return build(preorder, inorder, indx,0,inorder.size()-1);
    }
};