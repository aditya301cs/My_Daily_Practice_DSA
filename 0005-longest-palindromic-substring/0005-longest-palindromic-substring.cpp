class Solution {
public:
    // Helper function to expand around the center
    string expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    // Main function to find the longest palindromic substring
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        string res = "";

        for (int i = 0; i < s.size(); i++) {
            // Odd length palindrome
            string odd = expandAroundCenter(s, i, i);
            if (odd.size() > res.size()) res = odd;

            // Even length palindrome
            string even = expandAroundCenter(s, i, i + 1);
            if (even.size() > res.size()) res = even;
        }

        return res;
    }
};
