#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Optional safety: handle k == 0 (problem constraints say k >= 1, but this is defensive)
        if (k == 0) {
            for (int i = 0; i + 1 < (int)nums.size(); ++i)
                if (nums[i] == 0 && nums[i+1] == 0) return true;
            return false;
        }

        unordered_map<int,int> remIndex;
        remIndex.reserve(nums.size());
        remIndex[0] = -1;                 // remainder 0 seen at index -1 (prefix before array)

        long long prefix = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            prefix += nums[i];
            int rem = (int)(prefix % k); // k > 0, safe
            auto it = remIndex.find(rem);
            if (it != remIndex.end()) {
                if (i - it->second >= 2) return true;
            } else {
                // store earliest index for this remainder
                remIndex[rem] = i;
            }
        }
        return false;
    }
};
