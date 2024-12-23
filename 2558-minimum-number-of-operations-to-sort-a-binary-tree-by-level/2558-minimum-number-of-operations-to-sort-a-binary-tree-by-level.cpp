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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int op=0;

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            op+=minSwapReq(level);
        }
        return op;
    }
private:
    int minSwapReq(vector<int>& arr){
        int n = arr.size();
        vector<pair<int, int>> ap(n);
        for(int i=0;i<n;i++){
            ap[i].first = arr[i];
            ap[i].second = i;
        }
        sort(ap.begin(), ap.end());
        vector<bool> vis(n, false);
        int swap=0;
        for(int i=0;i<n;i++){
            int oldPos = ap[i].second;
            if(vis[i] && oldPos==i){
                continue;
            }
            int node=i;
            int cycle=0;
            while(!vis[node]){
                vis[node]=true;
                node= ap[node].second;
                cycle++;
            }
            if(cycle>1){
                swap += (cycle-1);
            }
        }
        return swap;
    }
};