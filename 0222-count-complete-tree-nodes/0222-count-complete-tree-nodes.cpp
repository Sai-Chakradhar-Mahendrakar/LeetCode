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
    // T: (O(log^2(n))
    // Function to compute the height of the tree
    
    
    int countNodes(TreeNode* root) {
        if (!root) return 0;  
        int l=0, r=0;
        TreeNode *lt=root, *rt=root;
        while(lt->left){
            lt = lt->left;
            l++;
        }

        while(rt->right){
            rt = rt->right;
            r++;
        }

        if(l==r){
            return (1<<(l+1))-1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};