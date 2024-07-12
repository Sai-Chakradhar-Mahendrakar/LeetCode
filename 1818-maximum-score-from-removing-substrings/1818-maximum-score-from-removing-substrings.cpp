#include <stack>
#include <string>

class Solution {
public:
    int maximumGain(std::string s, int x, int y) {
        // Prioritize the higher scoring pair
        char firstChar = x > y ? 'a' : 'b';
        char secondChar = x > y ? 'b' : 'a';
        int firstScore = std::max(x, y);
        int secondScore = std::min(x, y);

        int totalScore = 0;
        std::stack<char> st1;
        std::string remainingString;

        // First pass: remove the higher priority pairs
        for (char c : s) {
            if (!st1.empty() && st1.top() == firstChar && c == secondChar) {
                st1.pop();
                totalScore += firstScore;
            } else {
                st1.push(c);
            }
        }

        // Collect remaining characters
        while (!st1.empty()) {
            remainingString += st1.top();
            st1.pop();
        }

        // Reverse to maintain original order
        std::reverse(remainingString.begin(), remainingString.end());

        // Second pass: remove the lower priority pairs
        for (char c : remainingString) {
            if (!st1.empty() && st1.top() == secondChar && c == firstChar) {
                st1.pop();
                totalScore += secondScore;
            } else {
                st1.push(c);
            }
        }

        return totalScore;
    }
};
