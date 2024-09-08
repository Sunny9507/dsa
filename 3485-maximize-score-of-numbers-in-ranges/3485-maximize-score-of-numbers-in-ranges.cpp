class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int n = start.size();
        int l = 0;
        int r = start[n - 1] - start[0] + d + 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (isPossible(start, d, m)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l - 1;
    }

private:
    bool isPossible(const vector<int>& start, int d, int score) {
        int pre = start[0];
        for (int i = 1; i < start.size(); i++) {
            if (start[i] + d - pre < score) {
                return false;
            }
            pre = max(start[i], pre + score);
        }
        return true;
    }
};