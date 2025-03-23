class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        // Extract words and store in vector
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        // Join words with single space
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            if (i > 0)
                result += " ";
            result += words[i];
        }

        return result;
    }
};

// Steps to Solve:

// Trim leading and trailing spaces.

// Extract words manually by iterating over the string.

// Store words in a vector.

// Reverse the vector and concatenate words with a single space.
