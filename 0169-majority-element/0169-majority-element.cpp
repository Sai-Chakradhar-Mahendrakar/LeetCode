class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxVal=0;
        int maxCnt=0;
        for(int i=0;i<nums.size();i++){
            if(maxCnt==0){
                maxVal=nums[i];
            }
            if(maxVal==nums[i]){
                maxCnt++;
            }
            if(maxVal!=nums[i]){
                maxCnt--;
            }
        }
        return maxVal;
    }
};