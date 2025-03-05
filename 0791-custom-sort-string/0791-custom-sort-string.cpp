class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mp; // Map to count the frequency of each character in 's'
        string ans = "";   // To store the final sorted result

        // Count the frequency of each character in 's'
        for (auto x : s)
            mp[x]++;

        // Sort the characters in 's' according to the order in 'order'
        for (auto x : order) {
            if (mp.find(x) != mp.end()) { // Check if the character exists in the map
                auto temp = mp.find(x);   // Find the character in the map
                int count = temp->second; // Get the frequency of the character
                string str(count, x);     // Create a string with 'count' occurrences of 'x'
                ans += str;               // Append the occurrences to the result
                mp.erase(x);              // Remove the character from the map after processing
            }
        }

        // Add the remaining characters that were not in 'order'
        for (auto x : mp) {
            string str(x.second, x.first); // Create a string with 'x.second' occurrences of 'x.first'
            ans += str;                    // Append the occurrences to the result
        }

        return ans; // Return the final sorted string
    }
};
