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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }

        if(root->val>key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val<key){
            root->right = deleteNode(root->right, key);
        }
        else{
            if(root->left==NULL){
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
            }
            else if(root->right==NULL){
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
            }
            else{
                TreeNode* nodeToReplace = toReplace(root->right);
                root->val = nodeToReplace->val;
                root->right = deleteNode(root->right, nodeToReplace->val);
            }
        }
        return root;
    }
private:
    TreeNode* toReplace(TreeNode* root){
        while(root->left){
            root=root->left;
        }
        return root;
    }
};