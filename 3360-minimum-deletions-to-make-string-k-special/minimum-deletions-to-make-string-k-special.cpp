#include <vector>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<char, int> freqMap;
        for (char c : word) {
            freqMap[c]++;
        }
        
        vector<int> freq;
        for (auto& pair : freqMap) {
            freq.push_back(pair.second);
        }
        sort(freq.begin(), freq.end());
        
        int minDeletions = INT_MAX;
        int n = freq.size();
        
        for (int i = 0; i < n; ++i) {
            int targetMin = freq[i];
            int targetMax = targetMin + k;
            int deletions = 0;
            
            for (int j = 0; j < n; ++j) {
                if (freq[j] < targetMin) {
                    deletions += freq[j];
                } else if (freq[j] > targetMax) {
                    deletions += (freq[j] - targetMax);
                }
            }
            
            minDeletions = min(minDeletions, deletions);
        }
        
        return minDeletions;
    }
};