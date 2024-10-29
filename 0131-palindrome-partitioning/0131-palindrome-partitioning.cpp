class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> helper;
        vector<vector<string>> ans;
        solve(s, ans, helper, 0);
        return ans;
    }
private:
    bool isPalindrome(string s, int left, int right){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void solve(string s, vector<vector<string>>& ans, vector<string>& helper, int idx){
        if(idx>=s.size()){
            ans.push_back(helper);
            return;
        }

        for(int i=idx;i<s.size();i++){
            if(isPalindrome(s,idx, i)){
                helper.push_back(s.substr(idx, i-idx+1));
                solve(s, ans, helper, i+1);
                helper.pop_back();
            }
        }
    }
};