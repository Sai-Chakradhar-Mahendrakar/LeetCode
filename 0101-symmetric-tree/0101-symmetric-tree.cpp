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
    bool isSymmetric(TreeNode* root) {
        return isEqual(root->left, root->right);
    }
private:
    bool isEqual(TreeNode* lt, TreeNode* rt){
        if(lt==NULL && rt==NULL){
            return true;
        }

        if(lt==NULL || rt==NULL){
            return false;
        }

        return lt->val==rt->val && isEqual(lt->left, rt->right) && isEqual(lt->right, rt->left);
    }
};