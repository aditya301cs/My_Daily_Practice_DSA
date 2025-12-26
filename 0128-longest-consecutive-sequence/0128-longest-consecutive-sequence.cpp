class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> numSet(arr.begin(), arr.end());
    int maxLength = 0;

    for (int num : arr) {
        // Check if num is the start of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentLength = 1;

            // Count consecutive elements
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentLength++;
            }

            maxLength = max(maxLength, currentLength);
        }
    }

    return maxLength;
    }
};