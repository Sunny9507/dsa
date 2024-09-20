class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        // Create a DP vector initialized to 0
        vector<vector<int>> dp(height + 1, vector<int>(height + 1, 0));

        // Start from the second last row and move upwards
        for (int level = height - 1; level >= 0; level--) {
            for (int i = 0; i <= level; i++) {
                // Add the current triangle value to the minimum of the two adjacent values in the row below
                dp[level][i] = triangle[level][i] + min(dp[level + 1][i], dp[level + 1][i + 1]);
            }
        }

        // The top of the triangle will have the minimum path sum
        return dp[0][0];
    }
};