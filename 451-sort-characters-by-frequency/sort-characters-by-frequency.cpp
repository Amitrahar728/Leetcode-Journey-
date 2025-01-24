class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }
        vector<string> b(s.size() + 1);
        for (auto& pair : freqMap){
            char ch = pair.first;
            int freq = pair.second;
            b[freq] += string(freq, ch);
        }

        string result = "";
        for (int i = b.size() - 1; i > 0; i--) {
            if (!b[i].empty()) {
                result += b[i];
            }
        }

        return result;
    }
};