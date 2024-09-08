class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long res = 0;
        int mx = 0;
        for (int x : nums) {
            res += mx;
            mx = max(mx, x);
        }
        return res;
    }
};