//Approach-1 (Using sliding window + heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    typedef pair<int, int> P;

    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<P> maxPq;
        priority_queue<P, vector<P>, greater<P>> minPq;

        int i = 0;
        int j = 0;
        int maxLength = 0;

        while (j < n) {
            maxPq.push({nums[j], j});
            minPq.push({nums[j], j});

            while (maxPq.top().first - minPq.top().first > limit) {
                i = min(maxPq.top().second, minPq.top().second) + 1;

                while (maxPq.top().second < i) {
                    maxPq.pop();
                }
                while (minPq.top().second < i) {
                    minPq.pop();
                }
            }

            // Update maxLength with the length of the current valid window
            maxLength = max(maxLength, j - i + 1);
            j++;
        }

        return maxLength;
    }
};