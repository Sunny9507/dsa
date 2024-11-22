class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxRows = 0;

        for(auto& currRow : matrix){
            vector<int> inverted(n);

            for(int col = 0; col < n; col++){
                inverted[col] = currRow[col] == 0 ? 1 : 0;
            }
            int cnt = 0;

            for(auto &row : matrix){
                if(row == currRow || row == inverted){
                    cnt++;
                }
            }
            maxRows = max(maxRows, cnt);
        }   
        return maxRows;
    }
};