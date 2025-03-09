class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remFreq;
        remFreq[0] = 1; // To handle cases where subarray itself is divisible by k
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            int rem = sum % k;

            // If remainder is negative, adjust it to be positive
            if (rem < 0) {
                rem += k;
            }

            // If this remainder was seen before, add its count to result
            if (remFreq.find(rem) != remFreq.end()) {
                count += remFreq[rem];
            }
            // OR in one Line
            // count += remFreq[rem];

            // Increment frequency of this remainder
            remFreq[rem]++;
        }

        return count;

    }
};
