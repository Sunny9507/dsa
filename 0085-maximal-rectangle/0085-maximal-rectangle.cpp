class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);  // Add 0 to flush stack
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int>heights(col,0);

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == '0')
                    heights[j] = 0;
                else 
                    heights[j]++;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};