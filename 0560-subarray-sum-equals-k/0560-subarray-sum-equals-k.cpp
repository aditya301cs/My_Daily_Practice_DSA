class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> presum;
        presum[0] = 1; // Assume prefix sum 0 at index -1
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;

            // Check if (sum - k) exists in the map
            if (presum.find(sum - k) != presum.end()) 
                count += presum[sum - k];

            // Store/update the frequency of the current prefix sum
            presum[sum]++;
        }
        
        return count;
    }
};
