class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int n = s.size();
        int l = 0, r = 0, maxlen = 0;

        while (r < n) {
            if (seen.find(s[r]) == seen.end()) {
                seen.insert(s[r]);
                maxlen = max(maxlen, r - l + 1);
                r++;
            } else {
                seen.erase(s[l]);
                l++;
            }
        }

        return maxlen;
    }
};
