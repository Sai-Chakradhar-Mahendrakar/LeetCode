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
    // x->col, y->row
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, multiset<pair<int, int>>> mp; // [x][y, val]
            traversal(root, 0, 0, mp);
            vector<vector<int>> res;
            for(auto& [x, st] : mp)
            {
                res.push_back({});
                for(auto& [y, val] : st) {
                    res.back().push_back(val);
                }
            }
            return res;
    }
private:
    void traversal(TreeNode* node, int x, int y, auto &mp) {
        if(!node) return;
            mp[x].insert({y, node->val});
            traversal(node->left, x-1, y+1, mp);
            traversal(node->right, x+1, y+1, mp);
    }
};