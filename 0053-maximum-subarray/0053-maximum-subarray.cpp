class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int overAllSum = nums[0];
        int currentSum = nums[0];

        for(int i = 1; i<nums.size(); i++){
            if(currentSum >= 0){
                currentSum += nums[i];
            }else{
                currentSum = nums[i];  // currentSum = 0 + nums[i]
            }
            if(currentSum > overAllSum){
                overAllSum = currentSum;
            }
        }
        return overAllSum;
    }
};