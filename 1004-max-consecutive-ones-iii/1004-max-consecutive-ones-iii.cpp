class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;  // Two pointers for sliding window
        int maxLen = 0;

        while (j < nums.size()) {
            if (nums[j] == 0) {
                k--;  // Flip a zero
            }

            // If flips exceed the allowed `k`, shrink the window from the left
            while (k < 0) {
                if (nums[i] == 0) {
                    k++;  // Recover a flip when moving `i`
                }
                i++;  // Shrink the window
            }

            maxLen = max(maxLen, j - i + 1);
            j++;  // Expand the window
        }

        return maxLen;
    }
};
