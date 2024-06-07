class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        unordered_map<int,int> s;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int sum = target - nums[i];
            if(s.find(sum)!=s.end()){
                res.push_back(i);
                res.push_back(s[sum]);
            }
            s.insert({nums[i],i});
        }
        return res;
    }
};