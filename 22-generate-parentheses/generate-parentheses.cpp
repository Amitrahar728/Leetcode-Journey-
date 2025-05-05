class Solution {
public:

    void func(int n , vector<string> &ans , string &temp , int i =0,  int j =0 ){
            if(i == n && j ==n ){
                ans.push_back(temp);
                return ;
            }
            if(i+1<=n){
                temp.push_back('(');
                func(n,ans,temp,i+1,j);
                temp.pop_back();
            }
            if(j+1<=n && j+1<=i){
                temp.push_back(')');
                func(n,ans,temp , i , j+1);
                temp.pop_back();
            }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        func(n, ans, temp);
        return ans;

    }
};