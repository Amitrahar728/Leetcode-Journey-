class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> arr(26,0);  // s1 k record k liye 
        vector<int> arr2(26,0); // s2 k record k liye
        // Agar koi bhi window m jakr occurences of s1 equal ho s2 k tohh yes we have to return true 
        // r (front pointer) -> increase krte raho jabtak atleast utne element ajaye jitne s1 m hai 
        // l(previous pointer) --> if baaki characters mil jaye but kuch character jyada ho to l ko try kro 
        if(s1.length()>s2.length()){
            return false;
        }
        for(int i =0; i<s1.size(); i++){
            arr[s1[i]-'a']++;
        }

        int l = 0; int r = 0; 
        int n = s2.size();
        int m = s1.size();
        for(int i =0; i<n; i++){
            arr2[s2[i]-'a']++;
            if(i>=m){
                arr2[s2[i-m]-'a']--;
            }
            if(arr == arr2) return true;
        }
         return false;
    }
};