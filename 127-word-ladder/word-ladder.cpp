class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> list(wordList.begin(), wordList.end());
        list.erase(beginWord);

        while (!q.empty()) {
            auto frontElement = q.front();
            q.pop();

            string word = frontElement.first;
            int distance = frontElement.second;

            if (word == endWord) {
                return distance;
            }
            else {
                for (int i = 0; i < word.length(); i++) {
                    char org = word[i];
                    
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;

                        if (list.find(word) != list.end()) {
                            q.push({word, distance + 1});
                            list.erase(word);
                        }
                    }
                    word[i] = org;
                }
            }
        }
        return 0;
    }
};