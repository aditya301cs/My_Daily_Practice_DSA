class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        return doubled.find(s, 1) != s.size();
    }
};

// Explanation:
// Concatenate the string s with itself to form doubled = s + s.

// Use find(s, 1) to check if s appears again within doubled, but skip the first character to avoid matching the original s at the start.

// If find returns a position before s.size(), it means s is a repeating pattern. Otherwise, it's not.