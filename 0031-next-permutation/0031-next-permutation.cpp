class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n=nums.size();
        int i=n-2;
        while(i>=0 and nums[i]>=nums[i+1]){
            i--;
        } 
        if(i>=0){
            int j=n-1;
            while(nums[j]<=nums[i]){
                j--;
            }

            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};