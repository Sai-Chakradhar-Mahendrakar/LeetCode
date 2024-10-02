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
    int getDepth(TreeNode* node, bool left) {
        int depth = 0;
        while (node) {
            depth++;
            node = left ? node->left : node->right;
        }
        return depth;
    }
    
    int countNodes(TreeNode* root) {
        if (!root) return 0;  
        
        // Compute the leftmost and rightmost depths
        int leftDepth = getDepth(root, true);
        int rightDepth = getDepth(root, false);
        
        // If the depths are the same, the tree is full
        if (leftDepth == rightDepth) {
            return (1 << leftDepth) - 1;  // 2^depth - 1
        }
        
        // Otherwise, recursively count the nodes in the left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};