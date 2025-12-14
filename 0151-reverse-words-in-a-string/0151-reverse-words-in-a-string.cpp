class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string result = "";

        int i = n - 1;
        int j = n - 1;

        while (j >= 0) {
            // Skip trailing spaces
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
            if (i < 0) break;

            j = i;

            // Find the beginning of the word
            while (j >= 0 && s[j] != ' ') {
                j--;
            }

            // Add space between words
            if (!result.empty()) {
                result += ' ';
            }

            // Append the word
            for (int k = j + 1; k <= i; k++) {
                result += s[k];
            }

            i = j - 1;
            j--;
        }

        return result;
    }
};
