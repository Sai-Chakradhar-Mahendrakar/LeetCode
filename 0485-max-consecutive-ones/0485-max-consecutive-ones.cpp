class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
            }
            else{
                res = max(res, cnt);
                cnt=0;
            }
        }

        return max(res, cnt);
    }
};