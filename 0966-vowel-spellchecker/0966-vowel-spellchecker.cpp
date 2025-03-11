class Solution {
public:
    // Function to convert a word to lowercase
    string toLower(string word) {
        for (char& c : word)
            c = tolower(c);
        return word;
    }

    // Function to replace vowels with '*'
    string devowel(string word) {
        for (char& c : word) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '*';
        }
        return word;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactWords;
        unordered_map<string, string> caseInsensitiveMap, vowelErrorMap;

        // Store words in different forms
        for (string word : wordlist) {
            exactWords.insert(word);
            string lower = toLower(word);
            string devowelWord = devowel(lower);

            if (!caseInsensitiveMap.count(lower))
                caseInsensitiveMap[lower] = word;
            if (!vowelErrorMap.count(devowelWord))
                vowelErrorMap[devowelWord] = word;
        }

        vector<string> result;
        for (string query : queries) {
            if (exactWords.count(query)) {
                result.push_back(query);
            } else {
                string lowerQuery = toLower(query);
                string devowelQuery = devowel(lowerQuery);

                if (caseInsensitiveMap.count(lowerQuery)) {
                    result.push_back(caseInsensitiveMap[lowerQuery]);
                } else if (vowelErrorMap.count(devowelQuery)) {
                    result.push_back(vowelErrorMap[devowelQuery]);
                } else {
                    result.push_back("");
                }
            }
        }
        return result;
    }
};