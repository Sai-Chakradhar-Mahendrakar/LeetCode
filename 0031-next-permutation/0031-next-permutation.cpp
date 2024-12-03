class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0 and nums[i]>=nums[i+1]){
            i--;
        }
        cout<<i<<endl; 
        if(i>=0){
            int j=n-1;
            while(nums[j]<=nums[i]){
                j--;
            }

            cout<<j<<endl;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};