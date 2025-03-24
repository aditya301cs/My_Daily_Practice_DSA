class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map = {{'I', 1},   {'V', 5},   {'X', 10},
                                        {'L', 50},  {'C', 100}, {'D', 500},
                                        {'M', 1000}};

        int result = map[s.back()]; // Start from the last character

        for (int i = s.length() - 2; i >= 0; i--) {
            if (map[s[i]] < map[s[i + 1]]) {
                result -= map[s[i]];
            } else {
                result += map[s[i]];
            }
        }

        return result;
    }
};