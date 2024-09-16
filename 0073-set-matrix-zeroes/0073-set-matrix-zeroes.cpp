class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Number of rows
        int m = matrix[0].size(); // Number of columns
        
        vector<int>x, y; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        // row-> 0
        for (int i = 0; i < x.size(); i++) {
            int indx = x[i];
            for(int j=0; j<m; j++){
                matrix[indx][j] = 0;
            }
        }
        // col-> 0
        for (int i = 0; i < y.size(); i++) {
            int indx = y[i];
            for(int j=0; j<n; j++){
                matrix[j][indx] = 0;
            }
        }
    }
};