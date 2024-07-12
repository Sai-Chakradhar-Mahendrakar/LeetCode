class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Define the priority of pairs based on their scores
        char firstChar = x > y ? 'a' : 'b';
        char secondChar = x > y ? 'b' : 'a';
        int firstScore = max(x, y);
        int secondScore = min(x, y);

        // Calculate total score by removing pairs
        int totalScore = 0;
        totalScore += removePairs(s, firstChar, secondChar, firstScore);
        totalScore += removePairs(s, secondChar, firstChar, secondScore);

        return totalScore;
    }

private:
    int removePairs(string& s, char firstChar, char secondChar, int score) {
        stack<char> st;
        int pairsCount = 0;

        for (char c : s) {
            if (!st.empty() && st.top() == firstChar && c == secondChar) {
                st.pop();
                pairsCount++;
            } else {
                st.push(c);
            }
        }

        // Reconstruct the remaining string after removing pairs
        s="";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());

        return pairsCount * score;
    }
};
