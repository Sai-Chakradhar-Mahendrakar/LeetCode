class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        int mod = 1e9+7;
        for (int i = 1; i < rowIndex; ++i) {
            row[i] = ((long long)row[i - 1] * (rowIndex - i + 1)) / i;
        }

        return row;
    }
};