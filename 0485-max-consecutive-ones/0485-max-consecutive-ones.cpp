class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int ans=0;
        for(auto x:nums){
            if(x==1){
                cnt++;
            }
            else{
                ans = max(ans, cnt);
                cnt=0;
            }
        }
        ans= max(ans,cnt);
        return ans;
    }
};