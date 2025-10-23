class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int>mpp;
        int i = 0;
        int maxSize = 0;

        for(int j = 0; j < n; j++){
            mpp[nums[j]]++;
            while(mpp[nums[j]] > k){
                mpp[nums[i]]--;
                i++;
            }
            maxSize = max(maxSize, j - i + 1);
        }
        return maxSize;
    }
};