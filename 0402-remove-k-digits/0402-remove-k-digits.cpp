class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n==k){
            return "0";
        }

        stack<char> st;
        for(auto ch:num){
            while(!st.empty() && k>0 && st.top()>ch){
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while(k>0){
            st.pop();
            k--;
        }

        string res;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        int start=0;
        while(start<res.size()&&res[start]=='0'){
            start++;
        }

        res = res.substr(start);
        return res.empty() ? "0" : res;
    }
};