class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        for (char c : t)
            freq[c]++;
        int left = 0, minLen = INT_MAX, count = 0, start = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (--freq[s[right]] >= 0)
                ++count;
            while (count == t.size()) {
                if (minLen > right - left + 1) {
                    minLen = right - left + 1;
                    start = left;
                }
                if (++freq[s[left++]] > 0)
                    --count;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};