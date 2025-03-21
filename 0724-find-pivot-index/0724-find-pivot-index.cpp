class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(),nums.end(),0);
        for(int idx = 0; idx < n; idx++){
            rightSum -= nums[idx];

            if(leftSum == rightSum){
                return idx;
            }
            leftSum += nums[idx];
        }
        return -1;
    }
};