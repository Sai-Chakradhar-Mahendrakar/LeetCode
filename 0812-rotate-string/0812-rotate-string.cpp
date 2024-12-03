class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();

        if(n!=goal.length()){
            return false;
        }

        // Use KMP Algorithm
        string concatenated = s + s;
        return concatenated.find(goal) != string::npos; //-1
        
    }
};