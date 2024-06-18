class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> answer(m, vector<int>(n, 0));

        // Compute Prefix Sum Matrix
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = mat[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
            }
        }

        // Compute the Answer Matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r1 = max(i - k, 0);
                int c1 = max(j - k, 0);
                int r2 = min(i + k + 1, m);
                int c2 = min(j + k + 1, n);
                answer[i][j] = prefixSum[r2][c2] - prefixSum[r2][c1] - prefixSum[r1][c2] + prefixSum[r1][c1];
            }
        }

        return answer;
    }
};