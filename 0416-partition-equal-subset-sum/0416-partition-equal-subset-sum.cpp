class Solution {
public:
    bool solve(vector<int>& nums, int n, int target, vector<vector<int>>&memo){
        if(target == 0) return true;
        if(n == 0) return false;

        if(memo[n][target] != -1) return memo[n][target];


        if(nums[n-1] > target) 
            return memo[n][target] = solve(nums, n-1, target, memo);

        return memo[n][target] = solve(nums, n-1, target, memo) || 
                                 solve(nums, n - 1, target - nums[n - 1], memo);
    } 
    bool validPartition(vector<int>& nums, int n, int target){
        vector<vector<int>>memo(n+1, vector<int>(target+1, -1));
        return solve(nums, n, target, memo);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        int target = 0;
        
        for(auto & x : nums) totalSum += x;

        target = totalSum / 2;

        if(totalSum % 2 != 0) return false;

        return validPartition(nums, n, target);
    }
};