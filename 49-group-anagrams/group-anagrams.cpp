class Solution {
public:
    string solve(const string& s){
        vector<int> cnt(26,0);
        for(char c:s){
            cnt[c-'a']++;
        }
        
        stringstream ss; // instead of again and again using += operator this is more efficient than that one 
        // for this we need to include<sstream> header file in c++ code file

        for(int i =0; i<26; i++){
            if(cnt[i]!=0){
                ss<<(char)('a'+i)<<cnt[i];
            }
        }
        return ss.str(); // returns the complete concatenated string jo mili hai 
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        //  Anagrams : strings which can be formed by each other by swapping some palces
    //  BRUTE WAY TO SOLVE: 
        // T.C. = O(N*N) , S.C. = O(N*26);




        vector<vector<string>> res; // every anagram pair in each 
        // vector<vector<int>> freq(strs.size() , vector<int>(26,0)); // haar string ki freq count krne k liye

        // for(int i =0 ; i<strs.size(); i++)
        // {
        //     for(int j =0; j<strs[i].size(); j++){
        //         freq[i][strs[i][j]-'a']++;
        //     }
            
        // }
        // vector<bool> visited(strs.size(), false);

        // for(int i =0; i<strs.size(); i++){
        //     if(visited[i] == true){
        //         continue;
        //     }
        //     visited[i] = true;
        //     vector<string> res1;
        //     res1.push_back(strs[i]);
        //     for(int j =i+1; j<strs.size(); j++){
        //         if(visited[j]){
        //             continue;
        //         }
        //         if(freq[i] == freq[j]){
        //             res1.push_back(strs[j]);
        //             visited[j] = true;
        //         }
        //     }
        //     res.push_back(res1);
        // }
        // return res;


    // OPTIMAL WAY : 
    // T.C. = O(n∗k)
    // S.C. = O(n∗k)
    
    unordered_map<string, vector<string>> groups ;

        for(const string& s : strs){
             groups[solve(s)].push_back(s);
        }

        for (const auto& entry : groups) {
            res.push_back(entry.second);
        }

        return res;

    }
};