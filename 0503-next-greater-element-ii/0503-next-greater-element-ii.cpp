class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n,-1);
        for(int i=0;i<2*n;i++){
            int num = nums[i%n];
            while(!st.empty() && nums[st.top()]<num){
                res[st.top()] = num;
                st.pop();
            }
            if(i<n){
                st.push(i);
            }
        }
        return res;
    }
};