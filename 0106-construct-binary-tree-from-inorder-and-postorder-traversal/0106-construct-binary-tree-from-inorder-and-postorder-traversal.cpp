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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(), postorder.end());
        int idx=0;
        return build(inorder, postorder, idx, 0, inorder.size()-1);
    }
private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int& idx, int i, int j){
        if(i>j){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[idx]);

        int split;
        for(int k=i;k<=j;k++){
            if(postorder[idx]==inorder[k]){
                split=k;
                break;
            }
        }
        idx++;

        root->right=build(inorder, postorder, idx, split+1, j);
        root->left=build(inorder, postorder, idx, i, split-1);

        return root;
    }
};