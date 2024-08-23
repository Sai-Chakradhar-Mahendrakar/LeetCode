class Solution {
public:
    int beautySum(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans=0;

        for(int i=0;i<s.size();i++){
            int mp[26]={0};
            for(int j=i;j<s.size();j++){
                mp[s[j]-'a']++;

                int minFreq = INT_MAX;
                int maxFreq = INT_MIN;

                for(auto x:mp){
                    if(x>0){
                        maxFreq = max(maxFreq, x);
                        minFreq = min(minFreq, x);
                    }
                }
                ans+=(maxFreq-minFreq);
            }
        }
        return ans;
    }
};