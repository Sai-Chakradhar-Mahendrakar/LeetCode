class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0;i<n-3;i++){
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }

            for(int j=i+1;j<n-2;j++){
                if(j>i+1 and nums[j]==nums[j-1]){
                    continue;
                }

                int l=j+1;
                int r=n-1;

                while(l<r){
                    long long cur = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];                
                        if(cur==target){
                        res.insert({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;

                        while(l<r and nums[l]==nums[l-1]){
                            l++;
                        }

                        while(l<r and nums[r]==nums[r+1]){
                            r--;
                        }
                    }
                    else if(cur>target){
                        r--;
                    }
                    else{
                        l++;
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};