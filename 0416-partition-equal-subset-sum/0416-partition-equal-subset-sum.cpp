class Solution {
public:
    bool canSolve(int idx, vector<int>& nums, int target) {
        if (target == 0)
            return true;
        if (idx >= nums.size())
            return false;

        return canSolve(idx + 1, nums, target - nums[idx]) ||
               canSolve(idx + 1, nums, target);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0)
            return false;
        return canSolve(0, nums, sum / 2);
    }
};

// Time Complexity: O(2^n)
// Space Complexity: O(n)
