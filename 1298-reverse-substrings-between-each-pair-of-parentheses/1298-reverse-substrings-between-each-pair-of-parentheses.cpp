class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string ans;
        int n = s.length();

        for(auto ch:s){
            if(ch==')'){
                string temp;

                while (!st.empty() and st.top()!='(') {
                   temp += st.top();
                   st.pop();
                }

                if (!st.empty() and st.top()=='(') {
                    st.pop();
                }

                for (char t_ch : temp) {
                    st.push(t_ch);
                }
            }else{
                st.push(ch);
            }
        }

        while (!st.empty()) {
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};