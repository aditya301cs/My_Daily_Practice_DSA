class Solution {
 public:
  int minStartValue(vector<int>& nums) {
    int sum = 0;        // Tracks the cumulative sum (prefix sum)
    int minSum = 0;     // Tracks the smallest value of the cumulative sum

    for (const int num : nums)
      minSum = min(minSum, sum += num); // Update sum and minSum simultaneously

    return 1 - minSum;  // Return the minimum starting value to make all prefix sums >= 1
  }
};
