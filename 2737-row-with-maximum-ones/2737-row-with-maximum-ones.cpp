class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int maxRow = 0; 
        int maxCount = 0;
        
        for (int i = 0; i < n; ++i) {
            int currentCount = 0; 
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    currentCount++;
                }
            }
            
            if (currentCount > maxCount) {
                maxRow = i;
                maxCount = currentCount;
            }
        }
        
        return {maxRow, maxCount};
    }
};
