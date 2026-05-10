class Solution {
  public:
    int dp[301][5001];
    int solve(vector<int>& coins, int n, int sum){
        if(sum == 0) return 1;

        if(n == 0) return 0;
        
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        
        int include = 0;
        if(coins[n-1] <= sum){
            include = solve(coins, n, sum - coins[n-1]);
         }
        
        int exclude = solve(coins, n - 1, sum);
        
        return dp[n][sum] = include + exclude;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return solve(coins, coins.size(), amount);
    }
};