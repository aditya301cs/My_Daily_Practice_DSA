class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                      'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Move left pointer to find a vowel
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++;
            }
            // Move right pointer to find a vowel
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--;
            }

            // Swap vowels
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};