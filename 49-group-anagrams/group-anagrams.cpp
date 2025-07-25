class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //  Anagrams : strings which can be formed by each other by swapping some palces

        vector<vector<string>> res; // every anagram pair in each 
        vector<vector<int>> freq(strs.size() , vector<int>(26,0)); // haar string ki freq count krne k liye

        for(int i =0 ; i<strs.size(); i++)
        {
            for(int j =0; j<strs[i].size(); j++){
                freq[i][strs[i][j]-'a']++;
            }
            
        }
        vector<bool> visited(strs.size(), false);

        for(int i =0; i<strs.size(); i++){
            if(visited[i] == true){
                continue;
            }
            visited[i] = true;
            vector<string> res1;
            res1.push_back(strs[i]);
            for(int j =i+1; j<strs.size(); j++){
                if(visited[j]){
                    continue;
                }
                if(freq[i] == freq[j]){
                    res1.push_back(strs[j]);
                    visited[j] = true;
                }
            }
            res.push_back(res1);
        }
        return res;

    }
};