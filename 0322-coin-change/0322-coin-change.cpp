class Solution {
public:
    int dp[10001];

    int solve(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        if(amount < 0) return INT_MAX;

        if(dp[amount]!= -1) {
            return dp[amount];
        }

        int mini = INT_MAX;

        for(int i = 0; i<coins.size(); i++){
            int ans = solve(coins, amount - coins[i]);
            if(ans != INT_MAX){
                mini = min(mini, 1+ans);
            }
        }

        return dp[amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {

        memset(dp, -1, sizeof(dp));

        int ans = solve(coins, amount);

        return (ans == INT_MAX) ? -1 : ans;
    }
};