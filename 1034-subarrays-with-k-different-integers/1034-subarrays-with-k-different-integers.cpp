class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k)-atmost(nums, k-1);
    }
private:
    int atmost(vector<int>& nums, int k){
        int l=0;
        int r=0;
        int res=0;
        int n=nums.size();
        unordered_map<int, int> mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                if(--mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            res+=(r-l+1);
            r++;
        }
        return res;
    }
};