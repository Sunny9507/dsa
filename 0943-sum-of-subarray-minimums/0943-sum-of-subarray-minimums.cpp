class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> prevLess(n), nextLess(n);
        stack<int> s;

        // Previous Less Element
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            prevLess[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear stack for next iteration
        while (!s.empty()) s.pop();

        // Next Less Element
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            nextLess[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Calculate result
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prevLess[i];
            long long right = nextLess[i] - i;
            res = (res + (arr[i] * left % MOD) * right % MOD) % MOD;
        }

        return res;
    }
};
