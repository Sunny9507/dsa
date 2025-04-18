class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return f(n-1,m-1,word1,word2,dp)`;

        for(int i=0;i<dp[0].size();i++){
            dp[0][i] = i;
        }

        for(int i=0;i<dp.size();i++){
            dp[i][0] = i;
        }

        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        }
        return dp[word1.size()][word2.size()];

    }
};