class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(!n){
            return "";
        }

        sort(begin(strs), end(strs));
        string str1=strs[0];
        string str2=strs[n-1];
        string ans="";
        for(int i=0;i<str1.length();i++){
            if(str1[i]==str2[i]){
                ans+=str1[i];
            }
            else{
                break;
            }
        }
    
        return ans;
    }
};