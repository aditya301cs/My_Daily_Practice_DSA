class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort envelopes by width ascending, and if widths are equal, by height descending
        // The height descending ensures we don't mistakenly nest envelopes with same width
        sort(envelopes.begin(), envelopes.end(), [](const auto& envelope1, const auto& envelope2) {
            return envelope1[0] < envelope2[0] || 
                   (envelope1[0] == envelope2[0] && envelope1[1] > envelope2[1]);
        });
      
        int numEnvelopes = envelopes.size();
      
        // LIS array to track the smallest ending height for each subsequence length
        vector<int> lisHeights{envelopes[0][1]};
      
        // Process remaining envelopes to find LIS of heights
        for (int i = 1; i < numEnvelopes; ++i) {
            int currentHeight = envelopes[i][1];
          
            // If current height is larger than all previous, extend the sequence
            if (currentHeight > lisHeights.back()) {
                lisHeights.push_back(currentHeight);
            }
            else {
                // Find the position to replace with current height using binary search
                int replaceIndex = lower_bound(lisHeights.begin(), lisHeights.end(), currentHeight) 
                                   - lisHeights.begin();
              
                // Update the height at found position
                lisHeights[replaceIndex] = currentHeight;
            }
        }
      
        // The size of LIS array represents the maximum number of nested envelopes
        return lisHeights.size();
    }
};