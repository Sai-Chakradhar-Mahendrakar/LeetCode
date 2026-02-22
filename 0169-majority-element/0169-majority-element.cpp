class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxVal=0;
        int maxCnt=0;
        for(int num: nums){
            if(maxCnt==0){
                maxVal=num;
            } 
            if(maxVal==num) {
                maxCnt++;
            } 
            if(maxVal!=num) {
                maxCnt--;
            } 
        }
        return maxVal;
    }
};