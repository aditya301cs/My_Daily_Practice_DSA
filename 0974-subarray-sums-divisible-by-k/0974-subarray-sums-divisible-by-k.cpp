class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> remList(k, 0); 
        int sum = 0, ans = 0;
        remList[0] = 1;
        
        for (int i =0 ; i<nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;
            if(rem < 0){
                rem += k;
            }
            ans += remList[rem];
            remList[rem]++;
        }
        
        return ans;
    }
};
