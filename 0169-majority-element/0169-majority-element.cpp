class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int maxCnt = 0;
        int maxVal = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (maxCnt == 0) {
                maxVal = nums[i];
            }

            if (nums[i] == maxVal) {
                maxCnt++;
            }

            if (nums[i] != maxVal) {
                maxCnt--;
            }
        }
        return maxVal;
    }
};