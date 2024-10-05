class Solution {
public:
    bool isScrambleUtil(const string &s1, const string &s2, int start1, int end1, int start2, int end2, unordered_map<string, bool> &memo) {
    string key = to_string(start1) + '-' + to_string(end1) + '-' + to_string(start2) + '-' + to_string(end2);
    if (memo.find(key) != memo.end()) return memo[key];

    if (s1.substr(start1, end1 - start1 + 1) == s2.substr(start2, end2 - start2 + 1)) {
        return memo[key] = true;
    }

    string sub1 = s1.substr(start1, end1 - start1 + 1);
    string sub2 = s2.substr(start2, end2 - start2 + 1);

    auto sorted1 = sub1;
    auto sorted2 = sub2;
    sort(sorted1.begin(), sorted1.end());
    sort(sorted2.begin(), sorted2.end());

    if (sorted1 != sorted2) {
        return memo[key] = false;
    }

    int n = end1 - start1 + 1;

    for (int i = 1; i < n; ++i) {
        if (
            (isScrambleUtil(s1, s2, start1, start1 + i - 1, start2, start2 + i - 1, memo) &&
             isScrambleUtil(s1, s2, start1 + i, end1, start2 + i, end2, memo)) ||
            (isScrambleUtil(s1, s2, start1, start1 + i - 1, end2 - i + 1, end2, memo) &&
             isScrambleUtil(s1, s2, start1 + i, end1, start2, end2 - i, memo))
        ) {
            return memo[key] = true;
        }
    }

    return memo[key] = false;
}

    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        unordered_map<string, bool> memo;
        return isScrambleUtil(s1, s2, 0, s1.length() - 1, 0, s2.length() - 1, memo);
    }
};