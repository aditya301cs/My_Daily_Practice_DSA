class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        int countTuples = 0;

        // Store sums of pairs from nums1 and nums2
        for (int a : nums1) {
            for (int b : nums2) {
                mp[a + b]++;
            }
        }

        // Find complements from nums3 and nums4
        for (int c : nums3) {
            for (int d : nums4) {
                int target = -(c + d);
                if (mp.count(target)) {             //mp.count(target) returns 1 if target exists in the map, otherwise 0.
                                                    //If target exists, mp[target] retrieves its frequency (value stored for that key).
                    countTuples += mp[target];   
                }
                // We can use mp.find method to find tareget and its frequency
                // auto it = mp.find(target);
                // if (it != mp.end()) {
                // countTuples += it->second;
                // }
            }
        }

        return countTuples;
    }
};