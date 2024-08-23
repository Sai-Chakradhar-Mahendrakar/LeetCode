class Solution {
public:
    string longestPalindrome(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n=s.size();
        if(n==0){
            return "";
        }

        int start=0;
        int maxLen=1;

        for(int i=0;i<n;i++){
            int l1 = expandAroundCenter(s, i, i, n);
            int l2 = expandAroundCenter(s, i, i+1, n);

            int l = max(l1, l2);

            if(l>maxLen){
                start = i-(l-1)/2;
                maxLen = l;
            }
        }

        return s.substr(start, maxLen);
    }

private:
    int expandAroundCenter(string s, int left, int right, int n){
        while(left>=0 and right<n and s[left]==s[right]){
            left--;
            right++;
        }

        return right-left-1;
    }
};