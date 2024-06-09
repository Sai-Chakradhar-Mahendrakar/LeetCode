class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j=i+1;
            int k=n-1;
            int current_sum=0;
            while(j<k){
                current_sum=nums[i]+nums[j]+nums[k];
                if(current_sum==0){
                    cout<<nums[i]<<nums[j]<<nums[k]<<endl;
                    res.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                }
                else if(current_sum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
    return res;
    }
};