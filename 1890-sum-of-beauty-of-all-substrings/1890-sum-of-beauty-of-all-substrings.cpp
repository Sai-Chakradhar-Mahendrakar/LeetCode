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

                for(int k=0;k<26;k++){
                    if(mp[k]>0){
                        maxFreq = max(maxFreq, mp[k]);
                        minFreq = min(minFreq, mp[k]);
                    }
                }
                ans+=(maxFreq-minFreq);
            }
        }
        return ans;
    }
};