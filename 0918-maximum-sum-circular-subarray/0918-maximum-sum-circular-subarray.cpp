class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = nums[0], currMax = nums[0];
        int minSum = nums[0], currMin = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);

            currMin = min(nums[i], currMin + nums[i]);
            minSum = min(minSum, currMin);

            totalSum += nums[i];
        }
        totalSum += nums[0]; // Add the first element

        // If all elements are negative
        if (maxSum < 0)
            return maxSum;

        return max(maxSum, totalSum - minSum);
    }
};