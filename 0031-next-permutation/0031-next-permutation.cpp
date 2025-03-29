class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (!next_permutation(nums.begin(), nums.end())) {
            // If nums is already the last permutation, return the first one
            sort(nums.begin(), nums.end());
        }
    }
};