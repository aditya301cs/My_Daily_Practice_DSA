class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        
        unordered_map<char, int> s1_map, s2_map;
        
        // Build frequency map for s1
        for (char c : s1) {
            s1_map[c]++;
        }
        
        int i = 0; // left pointer of the sliding window
        // Expand the window with right pointer j
        for (int j = 0; j < m; j++) {
            s2_map[s2[j]]++; // include new character
            
            // When window size exceeds s1's length, shrink from the left
            if (j - i + 1 > n) {
                s2_map[s2[i]]--;
                if (s2_map[s2[i]] == 0) {
                    s2_map.erase(s2[i]);
                }
                i++;
            }
            
            // Check if the frequency maps match when the window size equals s1's length
            if (j - i + 1 == n && s2_map == s1_map) {
                return true;
            }
        }
        return false;
    }
};
