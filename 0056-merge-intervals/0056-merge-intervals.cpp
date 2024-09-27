class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(int i=0; i<intervals.size(); i++){

// [[1,3],[2,6],[8,10],[15,18]] back [1][6]
        // 8 > 6
//  push [8][10]
            if(ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            }
            else{
                //  [1,3],[2,6] replace 3 with 6
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }        
        }
        return ans;
    }
};