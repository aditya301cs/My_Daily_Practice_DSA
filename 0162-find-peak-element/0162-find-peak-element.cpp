class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[mid + 1]) {
                // If the middle element is greater than the next element,
                // then the peak lies on the left side (including mid)
                right = mid;
            } else {
                // If the middle element is less than or equal to the next element,
                // then the peak lies on the right side (excluding mid)
                left = mid + 1;
            }
        }
        
        // When left == right, we have found the peak element
        return left;
    }
};
