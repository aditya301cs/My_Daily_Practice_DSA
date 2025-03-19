class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int Xor_Index = 0;
        int Xor_elem = 0;
        for(int i=0; i<=n; i++){
            Xor_Index ^= i;
        }
        for(int i=0; i<n; i++){
            Xor_elem ^= nums[i];
        }
        int result = Xor_Index ^ Xor_elem;
        return result;
    }
};