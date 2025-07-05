class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        // Count frequencies
        for (int num : arr) {
            freq[num]++;
        }

        int maxLucky = -1;

        // Check for lucky integers
        for (auto [num, count] : freq) {
            if (num == count) {
                maxLucky = max(maxLucky, num);
            }
        }

        return maxLucky;
    }
};
