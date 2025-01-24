class Solution {
public:
    int count(string s){
        int arr[26] ={0};
        for(int i =0; i<s.size(); i++){
            int index = s[i]-'a';
            arr[index]++;
        }
        int m =INT_MIN;  //max

        int n=INT_MAX;  //min
        for(int i=0; i<26; i++){
           if(arr[i] > 0) { 
            m = max(m, arr[i]);  
            n = min(n, arr[i]);  
        }
        }
        return m-n;
    }
    int beautySum(string s) {
        int total =0;
        // vector<string> arr;
       
        for(int i=0;i<s.size(); i++){
            for(int j =i;j<s.size(); j++){
                total +=count(s.substr(i,j-i+1));
                
            }
        }
        
        return total;

    }
};