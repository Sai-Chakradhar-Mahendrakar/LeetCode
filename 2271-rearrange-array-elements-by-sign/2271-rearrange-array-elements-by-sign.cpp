class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int pIdx=0;
        int nIdx=1;

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[pIdx]=nums[i];
                pIdx+=2;
            }
            else{
                ans[nIdx]=nums[i];
                nIdx+=2;
            }
        }

        return ans;
    }
};