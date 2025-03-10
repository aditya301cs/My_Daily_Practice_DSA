class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Check if 1 is present in the array
        bool hasOne = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                hasOne = true;
                break;
            }
        }
        if (!hasOne)
            return 1;

        // Step 2: Replace nums[i] <= 0 or nums[i] > n with 1
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }

        // Step 3: Make the value at the corresponding index negative if index
        // exists
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]); // Get the absolute value
            if (val <= n) {
                nums[val - 1] = -abs(nums[val - 1]); // Make it negative
            }
        }

        // Step 4: Find the first index which is still positive, return its
        // index + 1
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        // If all values are marked, return n + 1
        return n + 1;
    }
};