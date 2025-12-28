class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> arr;
        int m = target.size();
        int i =0;
        int value = 1;
        while(i<target.size() && value <=n){
            if(target[i] == value ){ 
                arr.push_back("Push");
                value++;
                i++;
            }
            else{
                arr.push_back("Push");
                arr.push_back("Pop");
                value++;
            }
            // i++;
        }
        return arr;
    }
};