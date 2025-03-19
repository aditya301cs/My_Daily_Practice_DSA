class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // Calculate the sum of numbers from 0 to n using the sum formula
        int expected_sum = n * (n + 1) / 2;
        
        // Calculate the sum of the elements in the array
        int actual_sum = 0;
        // for (int num : nums) {
        //     actual_sum += num;
        // }

        for(int i = 0; i<n; i++){
            actual_sum += nums[i];
        }
        
        // The missing number is the difference between the expected sum and the actual sum
        return expected_sum - actual_sum;
    }
};
