class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        
        int l=0;
        int r=0;
        
        while(r<nums.size()){
            while(!dq.empty() and nums[dq.back()]<nums[r]){
                dq.pop_back();
            }
            
            dq.push_back(r);
            
            if(l>dq.front()){
                dq.pop_front();
            }
            
            if(r+1>=k){
                res.push_back(nums[dq.front()]);
                l++;
            }
            r++;  
        }
        return res;
    }
};