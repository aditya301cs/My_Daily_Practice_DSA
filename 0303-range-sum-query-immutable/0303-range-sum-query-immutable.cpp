class NumArray {
    vector<int> prefixSums; // To store prefix sums
public:
    NumArray(vector<int>& nums) {
        // Initialize prefixSums with the same size as nums
        prefixSums = nums;
        for (int i = 1; i < prefixSums.size(); i++) { 
            prefixSums[i] += prefixSums[i - 1]; // Compute prefix sums
        }
    }
    
    int sumRange(int left, int right) {
        // Use prefix sums to calculate the sum in range [left, right]
        return left == 0 ? prefixSums[right] : prefixSums[right] - prefixSums[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left, right);
 */
