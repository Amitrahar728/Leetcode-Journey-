class Solution {
    public String mergeAlternately(String word1, String word2) {
        String ss = "";
        int i =0;
        int j =0;
        int cnt =0;
        while(i<word1.length() && j<word2.length()){
            if(cnt%2==0){
                ss+=word1.charAt(i);
                i++;
            }
            else{
                ss+=word2.charAt(j);
                j++;
            }
            cnt++;
        }
        if(i == word1.length() && j == word2.length()){
            return ss;
        }
        else if(i == word1.length() && j != word2.length()){
            while(j<word2.length()){
                ss+=word2.charAt(j);
                j++;
            }
            
        }
        else if(i != word1.length() && j == word2.length()){
            while(i<word1.length()){
                ss+=word1.charAt(i);
                i++;
            }
            
        }
        return ss;

    }
}