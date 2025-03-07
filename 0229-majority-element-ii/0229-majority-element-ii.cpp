class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(auto x : nums){
            mp[x]++;
        }
        int n = nums.size();
        vector<int> ans;
        for(auto &pair : mp){
            if(pair.second>n/3)
            ans.push_back(pair.first);
        }
        return ans;
    }
};