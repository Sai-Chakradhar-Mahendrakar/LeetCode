class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> com;
        comb(candidates, target, 0, res, com, 0);
        return res;
    }
private:
    void comb(vector<int>& candidates, int target, int op, vector<vector<int>>&res, vector<int>&com, int idx){
        if(op==target){
            res.push_back(com);
            return;
        }

        if(op>target || idx>=candidates.size()){
            return;
        }

        com.push_back(candidates[idx]);
        // include;
        comb(candidates, target, op+candidates[idx], res, com, idx);
        com.pop_back();
        // exclude
        comb(candidates, target, op, res, com, idx+1);
        
    }
};