class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        vector<int> s_map(256, -1);
        vector<int> t_map(256, -1);

        for (int i = 0; i < s.length(); i++) {
            if (s_map[s[i]] != t_map[t[i]])
                return false;

            s_map[s[i]] = t_map[t[i]] = i;
        }
        return true;
    }
};