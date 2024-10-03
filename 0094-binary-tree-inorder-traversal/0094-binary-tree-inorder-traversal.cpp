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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        while(cur!=NULL){
            if(cur->left==NULL){
                res.push_back(cur->val);
                cur = cur->right;
            }
            
            else{
                TreeNode* prev = cur->left;
                while(prev->right && prev->right!=cur){
                    prev = prev->right;
                }
                
                if(prev->right==NULL){
                    prev->right=cur;
                    cur = cur->left;
                }
                else{
                    prev->right = NULL;   
                    res.push_back(cur->val); 
                    cur = cur->right; 
                }
            }
        }
        return res;
    }
private:
    void inOrder(TreeNode* root, vector<int>& res){
        if(root==NULL){
            return;
        }

        inOrder(root->left, res);
        res.push_back(root->val);
        inOrder(root->right, res);
    }
};