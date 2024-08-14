class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);

        int pre=0;
        for(int i=1;i<n;i++){
            while(pre>0 and needle[i]!=needle[pre]){
                pre = lps[pre-1];
            }
            if(needle[pre]==needle[i]){
                pre+=1;
                lps[i]=pre;
            }
        }

        int m=0;
        for(int i=0;i<haystack.size();i++){
            while(m>0 and needle[m]!=haystack[i]){
                m=lps[m-1];
            }
            if(needle[m]==haystack[i]){
                m+=1;
            }
            if(m==n){
                return i-m+1;
            }
        }

        return -1;
        
    }
};