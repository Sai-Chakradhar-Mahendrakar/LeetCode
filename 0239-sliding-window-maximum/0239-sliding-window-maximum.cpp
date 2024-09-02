class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        deque<int> dq(k);
        vector<int> res;

        int i=0;
        for(i=0;i<k;i++){
            while(!dq.empty() and nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(;i<nums.size();i++){
            res.push_back(nums[dq.front()]);

            // overflow
            while(!dq.empty() and dq.front()<=i-k){
                dq.pop_front();
            }

            while(!dq.empty() and nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);

        return res;
    }
};