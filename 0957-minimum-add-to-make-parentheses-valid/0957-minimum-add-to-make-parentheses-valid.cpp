class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans=0;

        for(auto ch: s){
            if(ch==')'){
                if(st.empty()){
                    ans++;
                }
                else{
                    st.pop();
                }
            }
            else{
                st.push(ch);
            }
        }

        ans+=st.size();
        return ans;
    }
};