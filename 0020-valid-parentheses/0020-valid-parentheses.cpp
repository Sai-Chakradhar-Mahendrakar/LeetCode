class Solution {
public:
    bool isValid(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        stack<char> st;
        for(auto x: s){
            if(st.empty()){
                st.push(x);
            }else if(x=='{' or x=='(' or x=='['){
                st.push(x);
            }else if(x==')' and st.top()=='('){
                st.pop();
            }else if(x=='}' and st.top()=='{'){
                st.pop();
            }else if(x==']' and st.top()=='['){
                st.pop();
            }else{
                return false;
            }
        }
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};