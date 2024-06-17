class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int i = 0, j = cols - 1;

        while (i < rows && j >= 0) {
            int current = matrix[i][j];

            if (current == target) {
                return true;
            } else if (current < target) {
                // Move down (target might be in the same column or further down)
                i++;
            } else {
                // Move left (target must be in a previous column)
                j--;
            }
        }

        // Target not found
        return false;
    }
};
