class Solution {
public:
    int solve(int i, int currentSum, vector<int>& nums, int target, int totalSum, vector<vector<int>>&dp){
        if(i == nums.size()){
            if(currentSum == target) return true;
            else return false;
        }
        if(dp[i][currentSum + totalSum] != -1){
            return dp[i][currentSum + totalSum];
        }
        int plus = solve(i+1, currentSum + nums[i], nums, target, totalSum, dp);
        int minus = solve(i+1, currentSum - nums[i], nums, target, totalSum, dp);

        return dp[i][currentSum + totalSum] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        } 
        // range = [-totalSum , totalSum]
        vector<vector<int>>dp(n+1, vector<int>((2*totalSum )+ 1, -1));
        return solve(0, 0, nums, target, totalSum, dp);
    }
};