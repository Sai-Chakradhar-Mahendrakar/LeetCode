class Solution {
public:
    string minWindow(string s, string t) {
        int fs[256]={0}, fp[256]={0};
        for(int i=0;i<t.length();i++){
            fp[t[i]]++;
        }
        int cnt=0,start_ind=-1,min_win=INT_MAX,win_siz=0,start=0;
       for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            fs[ch]++;
            
            // Count how many characters from t are found in s
            if (fp[ch] != 0 && fs[ch] <= fp[ch]) {
                cnt++;
            }
            
            // When all characters of t are found in the current window
            if (cnt == t.length()) {
                // Try to minimize the window size
                while (fp[s[start]] == 0 || fs[s[start]] > fp[s[start]]) {
                    if (fs[s[start]] > fp[s[start]]) {
                        fs[s[start]]--;
                    }
                    start++;
                }
                
                // Update the minimum window size
                int win_siz = i - start + 1;
                if (min_win > win_siz) {
                    min_win = win_siz;
                    start_ind = start;
                }
            }
        }
        
        // If no window found, return an empty string
        if (start_ind == -1) {
            return "";
        }
        
        // Return the minimum window substring
        return s.substr(start_ind, min_win);
    }
};