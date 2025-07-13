#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool str(const string& s, const vector<string>& dict) {
        return find(dict.begin(), dict.end(), s) != dict.end();
    }

    vector<int> dp;
    const vector<string>* dict_ptr;

    bool wordBreak(const string& s, const vector<string>& wordDict, int start_idx) {
        if (start_idx == s.length()) {
            return true;
        }

        if (dp[start_idx] != -1) {
            return dp[start_idx] == 1;
        }

        for (int i = start_idx; i < s.length(); ++i) {
            string current_prefix = s.substr(start_idx, i - start_idx + 1);

            if (str(current_prefix, wordDict) && wordBreak(s, wordDict, i + 1)) {
                dp[start_idx] = 1;
                return true;
            }
        }

        dp[start_idx] = 0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.length(), -1);
        dict_ptr = &wordDict;
        return wordBreak(s, wordDict, 0);
    }
};