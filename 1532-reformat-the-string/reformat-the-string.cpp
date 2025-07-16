class Solution {
public:
    string reformat(string s) {
        int digitCount = 0, letterCount = 0, n = s.length();

        for (int i = 0; i < n; i++) {
            isdigit(s[i]) ? ++digitCount : ++letterCount;
        }

        if (abs(digitCount - letterCount) > 1) return "";
        bool digitFirst = digitCount >= letterCount;
        int d = 0, l = 0;
        string result(n, ' ');

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                result[digitFirst ? d : d + 1] = s[i];
                d += 2;
            } 
            else {
                result[digitFirst ? l + 1 : l] = s[i];
                l += 2;
            }
        }

        return result;
    }
};