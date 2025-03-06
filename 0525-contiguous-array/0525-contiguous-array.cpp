class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> presum;
        presum[0] = -1;  // Initial prefix sum at index -1 (handles case when sum is 0 at any point)
        int sum = 0, maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Convert 0 to -1
            sum += (nums[i] == 0) ? -1 : 1;

            // If the prefix sum is found before, it means a subarray with sum 0 exists
            if (presum.find(sum) != presum.end()) {
                maxLen = max(maxLen, i - presum[sum]);
            } else {
                // Store first occurrence of the prefix sum
                presum[sum] = i;
            }
        }
        
        return maxLen;
    }
};
