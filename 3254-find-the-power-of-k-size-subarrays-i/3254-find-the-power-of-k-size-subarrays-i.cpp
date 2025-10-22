class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n,-1);
        while(n > 0){
            for(int i = 0; i<k; i++){
                if(nums[i + 1] > nums[i]){
                    ans[k - i - 1] = nums[i];
                }
            }
        }
        return ans;
    }
};