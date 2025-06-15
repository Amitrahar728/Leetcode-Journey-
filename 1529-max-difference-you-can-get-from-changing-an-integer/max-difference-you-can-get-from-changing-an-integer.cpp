class Solution {
public:
    int maxDiff(int num) {
        std::string s_max = std::to_string(num);
        std::string s_min = std::to_string(num);

        // --- Calculate the Maximum Number ---
        char digit_to_replace_for_max = ' ';
        for (char c : s_max) {
            if (c != '9') {
                digit_to_replace_for_max = c;
                break;
            }
        }

        if (digit_to_replace_for_max != ' ') {
            for (char& c : s_max) {
                if (c == digit_to_replace_for_max) {
                    c = '9';
                }
            }
        }
        int maximum = std::stoi(s_max);

        // --- Calculate the Minimum Number ---
        char digit_to_replace_for_min = ' ';
        char replacement_for_min = ' ';

        if (s_min[0] != '1') {
            digit_to_replace_for_min = s_min[0];
            replacement_for_min = '1';
        } else {
            int i = 0;
            while (i < s_min.size()) {
                if (s_min[i] != '0' && s_min[i] != '1') {
                    digit_to_replace_for_min = s_min[i];
                    replacement_for_min = '0';
                    break;
                }
                i++;
            }
        }

        if (digit_to_replace_for_min != ' ') {
            for (char& c : s_min) {
                if (c == digit_to_replace_for_min) {
                    c = replacement_for_min;
                }
            }
        }
        int minimum = std::stoi(s_min);

        return maximum - minimum;
    }
};