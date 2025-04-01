

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> points(n, 0);
        for(int i = n-1; i >= 0; --i){
            points[i] = questions[i][0];
            if(i + questions[i][1] + 1 < n)
                points[i] = max(points[i] + points[i + questions[i][1] + 1], points[i+1]);
            else if(i < n-1)
                points[i] = max(points[i], points[i+1]);
        }
        return points[0];
    }
};