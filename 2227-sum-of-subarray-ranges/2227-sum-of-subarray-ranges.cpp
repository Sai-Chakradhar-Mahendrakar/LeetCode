class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        long long totalMax=0, totalMin=0;

        // totalMax
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || nums[st.top()]<nums[i])){
                int left = st.top();
                st.pop();
                int right = st.empty() ? -1 : st.top();
                totalMax += (long long)nums[left]*(i-left)*(left-right);
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        //totalMin
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || nums[st.top()]>nums[i])){
                int left = st.top();
                st.pop();
                int right = st.empty() ? -1 : st.top();
                totalMin += (long long)nums[left]*(i-left)*(left-right);
            }
            st.push(i);
        }
        return totalMax - totalMin;
    }
};