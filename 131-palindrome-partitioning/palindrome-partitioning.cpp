class Solution {
public:
    vector<vector<string>> res;

bool is_palindromic(string s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}

void find_partitions(string s, int i, int n, vector<string>& v) {
    if (i == n) {
        res.push_back(v);
        return;
    }
    for (int k = i; k < n; k++) {
        if (is_palindromic(s, i, k)) {
            v.push_back(s.substr(i, k - i + 1));
            find_partitions(s, k + 1, n, v);
            v.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    if (s.size() == 1)
        return {{s}};
    
    vector<string> v;
    find_partitions(s, 0, s.size(), v);
    return res;
}
};