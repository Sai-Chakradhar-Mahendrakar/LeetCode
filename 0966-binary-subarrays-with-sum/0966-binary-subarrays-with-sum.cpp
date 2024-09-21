class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal)-atmost(nums, goal-1);
    }
private:
    int atmost(auto& nums, auto goal){
        int l=0;
        int r=0;
        int n=nums.size();
        int sum=0;
        int cnt=0;

        if(goal<0){
            return 0;
        }

        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        
        return cnt;
    }
};