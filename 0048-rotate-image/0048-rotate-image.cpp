// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n=matrix.size(), m = matrix.size();
        
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 swap(matrix[i][j], matrix[j-1][i]);
//             }
//         }
//         return swap;
//     }
// };





class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {  // Iterate only up to diagonal to avoid duplicates
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
