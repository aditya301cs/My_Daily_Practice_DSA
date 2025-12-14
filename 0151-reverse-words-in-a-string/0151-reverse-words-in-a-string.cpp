// Steps to Solve:

// Trim leading and trailing spaces.

// Extract words manually by iterating over the string.

// Store words in a vector.

// Reverse the vector and concatenate words with a single space.

// Time Complexity: O(N)

// Space Complexity: O(N)

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

// Explanation of stringstream ss(s);
// 1️⃣ What is stringstream ss(s); Doing?
// stringstream ss(s); creates a stringstream object (ss) and initializes it with the string s.

// It allows us to treat s as a stream (like cin), enabling easy word extraction.

// 2️⃣ How Does stringstream ss(s); Work?
// Think of stringstream as a temporary input buffer containing s.
// It lets us extract words one by one as if we were reading from cin.


