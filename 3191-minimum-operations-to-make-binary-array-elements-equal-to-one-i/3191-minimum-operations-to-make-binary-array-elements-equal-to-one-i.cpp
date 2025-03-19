class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        // int j =0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                if(i+2 >= n) {
                    return -1;
                }
                count++;
            
                for(int j=i; j<min(i+3 , n); j++){
                    nums[j] = 1 - nums[j];
                }
            }
            // count++;
            // j = i;
        }
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                return -1;
            }
        }
        return count;
    }
};