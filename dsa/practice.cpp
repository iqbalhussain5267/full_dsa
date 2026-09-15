// spiral matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int total = n * m;
        int count = 0;

        vector<int> ans;

        int startRow = 0;
        int endRow = n - 1;
        int startCol = 0;
        int endCol = m - 1;

        while (count < total) {

            // Traverse Right
            for (int i = startCol; i <= endCol && count < total; i++) {
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;

            // Traverse Down
            for (int i = startRow; i <= endRow && count < total; i++) {
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            // Traverse Left
            for (int i = endCol; i >= startCol && count < total; i--) {
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            // Traverse Up
            for (int i = endRow; i >= startRow && count < total; i--) {
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;
        }

        return ans;
    }
};