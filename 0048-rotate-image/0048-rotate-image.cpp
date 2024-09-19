class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Create a temporary matrix to store the rotated elements
        vector<vector<int>> ans(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][n - i - 1] = matrix[i][j]; // Corrected index calculation
            }
        }

        // Copy the rotated elements back to the original matrix
        matrix = ans;
    }
};
