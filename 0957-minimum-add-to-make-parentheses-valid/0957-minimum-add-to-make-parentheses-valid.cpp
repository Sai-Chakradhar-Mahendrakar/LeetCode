class Solution {
public:
    int minAddToMakeValid(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
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