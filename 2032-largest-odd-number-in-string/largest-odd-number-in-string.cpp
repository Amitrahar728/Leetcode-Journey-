class Solution {
public:
    string largestOddNumber(string num) {
        int j =num.length()-1;
        while (j >= 0 && (num[j]-'0') % 2 == 0) {
            j--; 
        }
        if (j < 0) {
            return "";
        }

        return num.substr(0, j + 1);
    }
};