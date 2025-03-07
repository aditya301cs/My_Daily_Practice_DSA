class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>
            mp; // HashMap to store groups of anagrams

        // Iterate over each word in the input array
        for (string& s : strs) {
            vector<int> count(26, 0); // Frequency array to store letter counts

            // Count occurrences of each character in the string
            for (char ch : s) {
                count[ch - 'a']++; // Increment the count for the respective
                                   // character
            }

            // Generate a unique key from the frequency array
            string key = "";
            for (int freq : count) {
                key += to_string(freq) + "#"; //Creating a unique hashable string by Concatenating frequency values with a "#" separator
            }

            // Store the string in the corresponding anagram group
            mp[key].push_back(s);
        }

        // Convert the unordered_map values into a vector of anagram groups
        vector<vector<string>> result;
        for (auto& it : mp) {
            //result.push_back(it.second);     //it.second (the vector) into result, which can be slow for large input sizes.
            // std::move(it.second) is used to transfer ownership of the vector inside the unordered_map to result without making a deep copy.
            result.push_back(move(it.second)); //This moves it.second, leaving it empty in mp after transfer or Move to optimize performance
        }

        return result;
    }
}
;