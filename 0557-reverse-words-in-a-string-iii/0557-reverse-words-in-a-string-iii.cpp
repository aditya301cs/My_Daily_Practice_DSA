class Solution {
public:
    string reverseWords(string s) {
        int start = 0; // Keeps track of the beginning of each word

        for (int end = 0; end <= s.size(); end++) {
            // When we find a space or reach the end of the string, we reverse
            // the current word
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end); // Reverse the word from 'start' to 'end-1'
                start = end + 1; // Move 'start' to the beginning of the next word
            }
        }
        return s; // Return the modified string
    }
};