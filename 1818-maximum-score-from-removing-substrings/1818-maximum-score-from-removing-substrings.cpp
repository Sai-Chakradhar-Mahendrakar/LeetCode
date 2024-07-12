class Solution {
public:
    int maximumGain(std::string s, int x, int y) {
        // Define the priority of pairs based on their scores
        char firstChar = x > y ? 'a' : 'b';
        char secondChar = x > y ? 'b' : 'a';
        int firstScore = std::max(x, y);
        int secondScore = std::min(x, y);

        // Calculate total score by removing pairs
        int totalScore = 0;
        totalScore += removePairs(s, firstChar, secondChar, firstScore);
        totalScore += removePairs(s, secondChar, firstChar, secondScore);

        return totalScore;
    }

private:
    int removePairs(std::string& s, char firstChar, char secondChar, int score) {
        std::stack<char> st;
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
        std::string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        std::reverse(remaining.begin(), remaining.end());
        s = remaining;

        return pairsCount * score;
    }
};
