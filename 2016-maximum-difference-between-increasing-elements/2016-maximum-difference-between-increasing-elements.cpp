class Solution {
public:
    int maximumDifference(vector<int>& arr) {
        int n = arr.size();
        if (n < 2)
            return -1;

        vector<int> suffixMax(n);
        suffixMax[n - 1] = arr[n - 1];

        // Fill suffix max array
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(arr[i], suffixMax[i + 1]);
        }

        int max_diff = -1;

        // Find the maximum difference
        for (int i = 0; i < n - 1; i++) {
            if (suffixMax[i + 1] > arr[i]) {
                max_diff = max(max_diff, suffixMax[i + 1] - arr[i]);
            }
        }

        return max_diff;
    }
}
;