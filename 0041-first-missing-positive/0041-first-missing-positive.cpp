class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool containsOne = false;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                containsOne = true;
                break;
            }
        }
        if (containsOne == false) {
            return 1; 
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]);
            if (index <= n) {
                nums[index - 1] = -abs(nums[index - 1]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1; 
    }
};