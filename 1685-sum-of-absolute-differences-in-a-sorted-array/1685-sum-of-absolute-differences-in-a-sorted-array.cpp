class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        int left_sum = 0, right_sum = 0;
        for (int num : nums) right_sum += num;  // Compute total sum

        for (int i = 0; i < n; i++) {
            right_sum -= nums[i];  // Subtract current element from right sum
            int left_Contribution = (nums[i] * i - left_sum);
            int right_Contribution = (right_sum - nums[i] * (n - 1 - i));
            result[i] = left_Contribution + right_Contribution;
            left_sum += nums[i];   // Add current element to left sum
        }

        return result;
    }
};



