class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();  // Get the size of the height array
        
        // Edge case: If the array has less than 3 elements, no water can be trapped
        if (n < 3) return 0;

        // Create two arrays to store the maximum height to the left and right of each index
        vector<int> prefix_max(n);
        vector<int> suffix_max(n);

        // Initialize the prefix array (maximum height to the left of each index)
        prefix_max[0] = height[0];  // First element has no left side, so it is the same as height[0]
        for (int i = 1; i < n; i++) {
            // prefix[i] stores the maximum height from the left up to index i
            prefix_max[i] = max(prefix_max[i - 1], height[i]);
        }

        // Initialize the suffix array (maximum height to the right of each index)
        suffix_max[n - 1] = height[n - 1];  // Last element has no right side, so it is the same as height[n-1]
        for (int i = n - 2; i >= 0; i--) {
            // suffix[i] stores the maximum height from the right up to index i
            suffix_max[i] = max(suffix_max[i + 1], height[i]);
        }

        // Calculate the water that can be trapped
        int water = 0;
        for (int i = 1; i < n - 1; i++) {
            // The water trapped at index i is the minimum of the max heights on both sides minus the height at i
            water += min(prefix_max[i], suffix_max[i]) - height[i];
        }

        return water;  // Return the total trapped water
    }
};