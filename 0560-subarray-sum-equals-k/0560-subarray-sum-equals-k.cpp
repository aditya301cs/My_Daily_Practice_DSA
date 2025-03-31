class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixMap;
        prefixMap[0] = 1; // Assume prefix sum 0 at index -1
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;

            // Check if (sum - k) exists in the map
            if (prefixMap.find(sum - k) != prefixMap.end()) 
                count += prefixMap[sum - k];

            // Store/update the frequency of the current prefix sum
            prefixMap[sum]++;
        }
        
        return count;
    }
};
