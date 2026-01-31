class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ch = letters[0];
        for(char c : letters){
            if(int(target)<int(c)){
                ch = c;
                break;
            }
        }
        return ch;
    }
};