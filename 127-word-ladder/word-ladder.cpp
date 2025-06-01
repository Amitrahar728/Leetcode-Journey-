class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        wordSet.erase(beginWord);

        while (!q.empty()) {
            string currentWord = q.front().first;
            int level = q.front().second;
            q.pop();

            if (currentWord == endWord)
                return level;

            for (int i = 0; i < currentWord.size(); i++) {
                char originalChar = currentWord[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    currentWord[i] = c;
                    if (wordSet.find(currentWord) != wordSet.end()) {
                        wordSet.erase(currentWord);
                        q.push({currentWord, level + 1});
                    }
                }
                currentWord[i] = originalChar;
            }
        }
        return 0;
    }
};
