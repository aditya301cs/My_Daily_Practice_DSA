class Solution {
public:
    int solve(int i, int currentSum, vector<int>& nums, int target){
        if(i == nums.size()){
            if(currentSum == target) return true;
            else return false;
        }

        int plus = solve(i+1, currentSum + nums[i], nums, target);
        int minus = solve(i+1, currentSum - nums[i], nums, target);

        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, 0, nums, target);
    }
};