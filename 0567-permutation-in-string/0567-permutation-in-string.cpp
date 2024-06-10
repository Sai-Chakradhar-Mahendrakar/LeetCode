class Solution {
public:
    bool isPermutation(vector<int>count){
        for(int i=0;i<26;i++){
            if(count[i]!=0){
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        
        vector<int>count(26);
        
        if(m>n){
            return false;
        }
        
        for(int i=0;i<m;i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        
        if(isPermutation(count)){
            return true;
        }
        
        for(int i=m;i<n;i++){
            count[s2[i]-'a']--;
            count[s2[i-m]-'a']++;
            if(isPermutation(count)){
                return true;
            }
        }
        return false;
    }
};