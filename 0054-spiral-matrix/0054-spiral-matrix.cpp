class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        if (matrix.empty())
            return res;

        int startRow = 0;
        int endRow = matrix.size() - 1;
        int startCol = 0;
        int endCol = matrix[0].size() - 1;

        while (startRow <= endRow and startCol <= endCol) {
            // Start Row
            for (int i = startCol; i <= endCol; i++) {
                res.emplace_back(matrix[startRow][i]);
            }

            // End Col
            for (int i = startRow + 1; i <= endRow; i++) {
                res.emplace_back(matrix[i][endCol]);
            }

            // End Row
            for (int i = endCol - 1; i >= startCol; i--) {
                if(startRow==endRow){
                    break;
                }
                res.emplace_back(matrix[endRow][i]);
            }

            // Start Col
            for (int i = endRow - 1; i >= startRow+1; i--) {
                if(startCol==endCol){
                    break;
                }
                res.emplace_back(matrix[i][startCol]);
            }

            // Updating
            startRow++;
            endRow--;
            startCol++;
            endCol--;
        }
        return res;
    }
};