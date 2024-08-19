class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i=0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j=i+1;
            int k=n-1;
            
            while(j<k){
                int curSum= nums[i]+nums[j]+nums[k];
                if(curSum==0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                }
                else if(curSum>0){
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