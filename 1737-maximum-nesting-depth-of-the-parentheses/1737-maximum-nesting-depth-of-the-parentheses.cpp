class Solution {
public:
    int maxDepth(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int cnt=0;
        int ans=0;
        
        for(auto ch: s){
            if(ch=='('){
                cnt++;
                ans=max(ans, cnt);
            }
            else if(ch==')'){
                cnt--;
            }
        }
        return ans;
    }
};