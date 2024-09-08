class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recPerm(0, nums, ans);
        return ans;
    }
private:
    void recPerm(auto idx, auto& nums, auto& ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=idx;i<nums.size();i++){
            swap(nums[idx], nums[i]);
            recPerm(idx+1, nums, ans);
            swap(nums[idx], nums[i]);
        }
    }
};