class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int ast: asteroids){
            bool isDestroyed=false;

            while(!st.empty() && st.top()>0 && ast<0){
                if(st.top()<abs(ast)){
                    st.pop();
                }
                else if(st.top()==abs(ast)){
                    isDestroyed=true;
                    st.pop();
                    break;
                }
                else{
                    isDestroyed=true;
                    break;
                }
            } 

            if(!isDestroyed){
                st.push(ast);
            }
        }

        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};