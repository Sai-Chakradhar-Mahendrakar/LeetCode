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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if(root==NULL){
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> cur;
        bool leftToRight = true;

        while(!q.empty()){
            auto temp=q.front();
            q.pop();

            if(temp==NULL){
                if(!leftToRight){
                    reverse(cur.begin(), cur.end());
                }
                res.push_back(cur);
                cur.clear();
                leftToRight=!leftToRight;

                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                cur.push_back(temp->val);
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
        }
        return res;
    }
};