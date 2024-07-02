class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        int i = 0;
        while (i < n - 1) {
            if (i + nums[i] >= n - 1) {
                res++;
                break;
            }

            int maxIdx = i + 1;
            int maxVal = 0;

            for (int j = i + 1; j < i + 1 + nums[i]; j++) {
                if (j + nums[j] > maxVal) {
                    maxIdx = j;
                    maxVal = j + nums[j];
                }
            }
            i = maxIdx;
            res++;
        }

        return res;
    }
};