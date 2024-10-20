class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        backtrack(nums, res, cur, 0);
        return res;
    }
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>&cur, int idx){
        res.push_back(cur);

        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }

            cur.push_back(nums[i]);
            backtrack(nums, res, cur, i+1);
            cur.pop_back();
        }
    }
};