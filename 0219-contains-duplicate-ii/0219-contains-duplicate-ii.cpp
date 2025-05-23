class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int>Set;
        for(int i = 0; i<nums.size(); i++){
            if(Set.find(nums[i]) != Set.end()){
                return true;
            }
            Set.insert(nums[i]);
            if (Set.size() > k) {
                Set.erase(nums[i - k]);
            }
            
        }
        return false;
    }
};




