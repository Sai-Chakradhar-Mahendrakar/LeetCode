class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());

        while(--k){
            q.pop();
        }
        
        return q.top();
    }
};