class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxCnt=0;
        int maxInd=0;
        for(int i=0;i<nums.size();i++){
            if(maxCnt==0){
                maxInd = nums[i];
            }

            if(nums[i]==maxInd){
                maxCnt++;
            }

            if(nums[i]!=maxInd){
                maxCnt--;
            }
        }
        return maxInd;
    }
};