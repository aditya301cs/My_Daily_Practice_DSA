class Solution {
public:
    int dp[13][10001];
    const int INF = 1e9;

    int solve(vector<int>& coins, int n, int sum) {

        if(sum == 0) return 0;

        if(n == 0) return INF;

        if(dp[n][sum] != -1) {
            return dp[n][sum];
        }

        int take = INF;

        if(coins[n-1] <= sum) {
            take = 1 + solve(coins, n, sum - coins[n-1]);
        }

        int notTake = solve(coins, n-1, sum);

        return dp[n][sum] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {

        memset(dp, -1, sizeof(dp));

        int ans = solve(coins, coins.size(), amount);

        return (ans >= 1e9) ? -1 : ans;
    }
};