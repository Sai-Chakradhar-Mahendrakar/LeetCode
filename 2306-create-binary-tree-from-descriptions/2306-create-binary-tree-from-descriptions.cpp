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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, vector<pair<int, bool>>> parentChild;
        unordered_set<int> allNodes;
        unordered_set<int> child;

        for(auto x:descriptions){
            int par = x[0];
            int chi = x[1];
            bool isleft = x[2];

            parentChild[par].push_back({chi, isleft});
            allNodes.insert(par);
            allNodes.insert(chi);
            child.insert(chi);
        }

        int rootVal=0;
        for(int node: allNodes){
            if(!child.contains(node)){
                rootVal=node;
                break;
            }
        }

        return dfs(parentChild, rootVal);
    }

private:
    TreeNode* dfs(unordered_map<int, vector<pair<int, bool>>>&parentChild, int val){

        TreeNode* node = new TreeNode(val);

        if(parentChild.find(val)!=parentChild.end()){
            for(auto& child_info: parentChild[val]){
                int child = child_info.first;
                bool isLeft = child_info.second;

                if(isLeft){
                    node->left = dfs(parentChild, child);
                } else{
                    node-> right = dfs(parentChild, child);
                }
            }
        }
        return node;
    }
};