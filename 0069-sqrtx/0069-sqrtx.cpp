class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int mid;
        while (high - low > 1) {
            mid = low + (high - low) / 2;
            long long square = 1LL * mid * mid;  // prevent overflow
            if (square <= x) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
