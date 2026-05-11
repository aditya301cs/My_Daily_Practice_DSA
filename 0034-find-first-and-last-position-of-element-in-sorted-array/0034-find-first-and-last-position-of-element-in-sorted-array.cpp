class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int first_pos = -1;
        int second_pos = -1;

        for(int i = 0; i < n; i++) {
            if(nums[i] == target) {

                if(first_pos == -1)
                    first_pos = i;

                second_pos = i;
            }
        }

        return {first_pos, second_pos};
    }
};