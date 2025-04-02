class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int>ans(n,-1);
        bool found = false;
        for(int i = 0; i < n; i++){
            found = false;
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    found = true;
                }
                if(found && nums2[j] > nums1[i]){
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};