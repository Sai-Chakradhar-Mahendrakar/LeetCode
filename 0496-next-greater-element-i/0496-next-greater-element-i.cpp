class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) { 
        stack<int> st;
        unordered_map<int, int> mp;
        int n=nums2.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()<nums2[i]){
                int num = st.top();
                st.pop();
                mp[num]=nums2[i];
            }
            st.push(nums2[i]);
        }
        while(!st.empty()){
            int num = st.top();
            st.pop();
            mp[num]=-1;
        }

        vector<int> res;
        for(auto x:nums1){
            res.push_back(mp[x]);
        }

        return res;
    }
};