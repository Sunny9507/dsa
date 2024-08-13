class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (string word : wordDict) {
                int len = word.length();
                if (len <= i && s.substr(i - len, len) == word && dp[i - len]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
