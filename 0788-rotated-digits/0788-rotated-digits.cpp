class Solution {
public:
    bool isValid(int m) {
        bool changed = false;

        while (m > 0) {
            int digit = m % 10;
            if (digit == 3 || digit == 4 || digit == 7)
                return false;
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                changed = true;
            }

            m /= 10;
        }

        return changed;
    }

    int rotatedDigits(int n) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (isValid(i)) {
                count++;
            }
        }

        return count;
    }
};