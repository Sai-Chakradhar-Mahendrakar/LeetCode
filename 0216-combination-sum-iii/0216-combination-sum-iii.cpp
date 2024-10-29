class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(nums, res, cur, k, n, 0, 0);
        return res;
    }
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, int k, int n, int idx, int sum){
        if(cur.size()==k && sum==n){
            res.push_back(cur);
            return;
        }

        if(sum>n){
            return;
        }

        for(int i=idx;i<nums.size();i++){
            cur.push_back(nums[i]);
            backtrack(nums, res, cur, k, n, i+1, sum+nums[i]);
            cur.pop_back();
        }
    }
};