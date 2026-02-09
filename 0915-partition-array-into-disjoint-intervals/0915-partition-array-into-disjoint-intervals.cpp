class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int ans = 1; // assume the min. size of left part is 1
        int leftMaxSoFar = nums[0];
        int maxSoFar = nums[0];
        for(int i = 1; i < n; i++){
            maxSoFar = max(maxSoFar, nums[i]);
            if(nums[i] < leftMaxSoFar){
                ans = i + 1;
                leftMaxSoFar = maxSoFar; 
            }
        }
        return ans;
    }
};