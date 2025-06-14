class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        // For maximum: Replace the first non-'9' digit with '9'
        string maxStr = s;
        char toReplaceMax = '\0';
        for (char ch : s) {
            if (ch != '9') {
                toReplaceMax = ch;
                break;
            }
        }
        if (toReplaceMax) {
            for (char &ch : maxStr) {
                if (ch == toReplaceMax) ch = '9';
            }
        }
        int maxi = stoi(maxStr);

        // For minimum: Replace the first digit (not '0') with '0'
        string minStr = s;
        char toReplaceMin = s[0];
        for (char &ch : minStr) {
            if (ch == toReplaceMin) ch = '0';
        }
        int mini = stoi(minStr);

        return maxi - mini;
    }
};
