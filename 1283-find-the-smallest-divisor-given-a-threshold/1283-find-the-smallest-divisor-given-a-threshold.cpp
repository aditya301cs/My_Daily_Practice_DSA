class Solution {
public:
    int smallestDivisor(std::vector<int>& nums, int threshold) {
        int minDivisor = 1;
        int maxDivisor = *std::max_element(nums.begin(), nums.end());

        while (minDivisor < maxDivisor) {
            int divisor = (minDivisor + maxDivisor) / 2;

            if (isPossible(nums, divisor, threshold)) {
                maxDivisor = divisor;
            } else {
                minDivisor = divisor + 1;
            }
        }

        return maxDivisor;
    }

private:
    bool isPossible(const std::vector<int>& nums, int divisor, int threshold) {
        for (int num : nums) {
            threshold -= num / divisor;
            if (num % divisor != 0) {
                --threshold;
            }
            if (threshold < 0) {
                return false;
            }
        }
        return threshold >= 0;
    }
};
