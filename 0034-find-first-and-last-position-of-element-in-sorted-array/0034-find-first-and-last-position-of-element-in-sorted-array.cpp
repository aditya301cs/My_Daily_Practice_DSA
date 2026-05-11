class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        int first_pos = -1;
        int second_pos = -1;

        // Find first occurrence
        for(int i = 0; i < n; i++) {
            if(nums[i] == target) {
                first_pos = i;
                break;
            }
        }

        // Find last occurrence
        for(int j = n - 1; j >= 0; j--) {
            if(nums[j] == target) {
                second_pos = j;
                break;
            }
        }

        return {first_pos, second_pos};
    }
};