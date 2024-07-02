class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int check = 0;

        for(int i=0;i<n;i++){
            if(i>check){
                return false;
            }
            check = max(check, i+nums[i]);
            if(check>=n-1){
                break;
            }
        }
        return true;
    }
};