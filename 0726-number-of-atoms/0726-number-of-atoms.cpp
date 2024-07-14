class Solution {
public:
    string countOfAtoms(string formula) {
        // For every index, store the valid multiplier
        vector<int> muls(formula.length());
        int runningMul = 1;

        // Stack to take care of nested formula
        stack<int> stack;
        stack.push(1);

        // Preprocess the formula and extract all multipliers
        int index = formula.length() - 1;
        string currNumber = "";
        while (index >= 0) {
            if (isdigit(formula[index])) {
                currNumber = formula[index] + currNumber;
            }

            // If we encountered a letter, then the scanned
            // number was count and not a multiplier. Discard it.
            else if (isalpha(formula[index])) {
                currNumber = "";
            }

            // If we encounter a right parenthesis, then the
            // scanned number was multiplier. Store it.
            else if (formula[index] == ')') {
                int currMultiplier = currNumber.empty() ? 1 : stoi(currNumber);
                runningMul *= currMultiplier;
                stack.push(currMultiplier);
                currNumber = "";
            }

            // If we encounter a left parenthesis, then the
            // most recent multiplier will cease to exist.
            else if (formula[index] == '(') {
                runningMul /= stack.top();
                stack.pop();
                currNumber = "";
            }

            // For every index, store the valid multiplier
            muls[index] = runningMul;
            index--;
        }

        // Map to store the count of atoms
        unordered_map<string, int> finalMap;

        // Traverse left to right in the formula
        index = 0;
        while (index < formula.length()) {
            // If UPPER CASE LETTER, extract the entire atom
            if (isupper(formula[index])) {
                string currAtom = "";
                currAtom += formula[index];
                string currCount = "";
                index++;
                while (index < formula.length() && islower(formula[index])) {
                    currAtom += formula[index];
                    index++;
                }

                // Extract the count
                while (index < formula.length() && isdigit(formula[index])) {
                    currCount += formula[index];
                    index++;
                }

                // Update the final map
                int count = currCount.empty() ? 1 : stoi(currCount);
                finalMap[currAtom] += count * muls[index - 1];
            } else {
                index++;
            }
        }

        // Sort the final map
        map<string, int> sortedMap(finalMap.begin(), finalMap.end());

        // Generate the answer string
        string ans;
        for (auto& [atom, count] : sortedMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }
};