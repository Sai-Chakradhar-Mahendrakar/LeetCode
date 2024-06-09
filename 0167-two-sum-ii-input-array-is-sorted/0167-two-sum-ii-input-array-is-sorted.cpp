class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i=0,j=n-1;
        while(i<j){
            int sum = numbers[i]+numbers[j];
            if(sum==target){
                return vector<int>{i+1,j+1};
            }
            else{
                sum>target?j--:i++;
            }
        }
        return vector<int>{};
    }
};