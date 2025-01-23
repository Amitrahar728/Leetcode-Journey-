class Solution {
public:
    bool check (int a[26], int b[26]){
        for(int i =0;i<26; i++){
            if(a[i]!=b[i]){
                return 0; 
            }
            

        }
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        int arr1[26] ={0};
        for(int i =0; i<s1.length(); i++){
            int index = s1[i]-'a';
            arr1[index]++;
        }
        int i =0;
        int w = s1.length();
        int arr2[26] ={0};
        while(i<w && i <s2.length()){
            int index = s2[i]-'a';
            arr2[index]++;
            i++;
        }
         
         if(check(arr1,arr2)){
            return 1;
         }
         while(i<s2.length()){
            char newchar = s2[i];
            int index = newchar -'a';
            arr2[index]++;
            char oldchar = s2[i-w];
            index = oldchar -'a';
            arr2[index]--;
            i++;

            if(check(arr1,arr2)){
            return 1;
         }
         }
         return 0;
    }
};