class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] ={};
        if(s.length()!= t.length()) return false;
        for(int i =0; i<s.size(); i++){
            int index = s[i]-'a';
            int index2 = t[i]-'a';
            arr[index]++;
            arr[index2]--;
        }
        for(int i =0; i<26; i++){
            if(arr[i]!=0) return false ;
        }
        return true;
    }
};