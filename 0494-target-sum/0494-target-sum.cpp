class Solution {
public:
    int solve(int i, int currentSum, vector<int>& nums, int target, unordered_map<string, int>&mp){
        if(i == nums.size()){
            if(currentSum == target) return true;
            else return false;
        }
        string key = to_string(i) + "_" + to_string(currentSum);

        if(mp.count(key)){ //(mp.find(key) != mp.end())
            return mp[key];
        }
        int plus = solve(i+1, currentSum + nums[i], nums, target, mp);
        int minus = solve(i+1, currentSum - nums[i], nums, target, mp);

        return mp[key] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,  int>mp;
        return solve(0, 0, nums, target, mp);
    }
};