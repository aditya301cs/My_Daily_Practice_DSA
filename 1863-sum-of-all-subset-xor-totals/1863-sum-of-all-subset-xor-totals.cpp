//Approach-3 (Observing pattern)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int &num : nums) {
            result |= num;
        }

        return result << (n-1);
    }
};