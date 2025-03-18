class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
    int n = nums.size();
    int left = 0; // Left pointer of the sliding window
    int max_len = 1; // Minimum length is 1 (subarrays of length 1 are always nice)
    int current_or = 0; // Tracks the bitwise OR of the current window

    for (int right = 0; right < n; ++right) {
        // If the current element conflicts with the current window, shrink the window
        while ((current_or & nums[right]) != 0) {
            current_or ^= nums[left]; // Remove the left element from the window
            left++; // Move the left pointer
        }

        // Add the current element to the window
        current_or |= nums[right];

        // Update the maximum window size
        max_len = max(max_len, right - left + 1);
    }

    return max_len;
    }
};