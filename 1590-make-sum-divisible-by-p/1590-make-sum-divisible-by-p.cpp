class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> map;
        map[0] = -1; // To handle cases where prefix sum itself satisfies the condition
        
        int prefixSum = 0, total = 0, minLength = nums.size();

        for (int num : nums) {
            total = (total + num) % p;
        }

        int need = total % p;
        if (need == 0) return 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum = (prefixSum + nums[i]) % p;
            int want = (prefixSum - need + p) % p;
            
            if (map.find(want) != map.end()) {
                minLength = min(minLength, i - map[want]);
            }
            
            map[prefixSum] = i; // Store the latest index for this remainder
        }

        return minLength == nums.size() ? -1 : minLength;
    }
};
