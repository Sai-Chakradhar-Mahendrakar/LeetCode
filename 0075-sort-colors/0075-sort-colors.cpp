class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros=0;
        int ones=0;
        int twos=nums.size()-1;
        while(ones<=twos){
            if(nums[ones]==0){
                swap(nums[ones], nums[zeros]);
                ones++;
                zeros++;
            }
            else if(nums[ones]==1){
                ones++;
            }
            else{
                swap(nums[ones], nums[twos]);
                twos--;
            }
        }
    }
};