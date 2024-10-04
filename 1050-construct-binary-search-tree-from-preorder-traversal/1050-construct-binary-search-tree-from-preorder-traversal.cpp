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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size()-1);
    }
private:
    TreeNode* helper(vector<int>& preorder, int start, int end){
        if(start>end){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[start]);

        int split=end+1;
        for(int i=start;i<=end;i++){
            if(preorder[i]>preorder[start]){
                split=i;
                break;
            }
        }

        root->left = helper(preorder, start+1, split-1);
        root->right = helper(preorder, split, end);
        return root;
    }
};