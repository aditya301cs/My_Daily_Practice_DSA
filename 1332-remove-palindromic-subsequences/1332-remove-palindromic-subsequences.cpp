class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        return s.empty() ? 0 : (isPalindrome(s) ? 1 : 2);
    }
};


// Key Points to Solve the Problem

// If the string s is empty, return 0.
// Nothing to remove.

// If s is already a palindrome, return 1.

// Example: "ababa" → Remove in one step.

// If s is not a palindrome, return 2.

// We can remove all 'a's in one step, then all 'b's in another.

// Example: "baabb" → Remove "baab", then "b".