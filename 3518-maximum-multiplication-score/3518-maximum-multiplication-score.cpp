class Solution {
public:
    long long solve(vector<int>& a ,vector<int>& b , int i ,int j ,vector<vector<long long>>& dp){
        if(i==4){
            return 0;
        }
        if(j>=b.size()){
            return INT_MIN;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        long long take=(long long )a[i]*b[j] + solve(a,b,i+1,j+1,dp);
        long long  not_take=solve(a,b,i,j+1,dp);

        return dp[i][j] = max(take,not_take);
    }
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n=a.size();
         vector<vector<long long>>dp(n,vector<long long>(100005,-1));
         return solve(a,b,0,0,dp);

    }
};