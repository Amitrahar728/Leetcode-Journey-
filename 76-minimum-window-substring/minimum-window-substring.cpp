class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        vector<int> hash(128, 0);
        for (char c : t) {
            hash[c]++;
        }

        int required = t.size(); 
        int l = 0, r = 0, minlen = INT_MAX, start = 0;

        while (r < s.size()) {
            if (hash[s[r]] > 0) required--;
            hash[s[r]]--;

            while (required == 0) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    start = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0) required++;
                l++;
            }
            r++;
        }

        return minlen == INT_MAX ? "" : s.substr(start, minlen);
    }
};
