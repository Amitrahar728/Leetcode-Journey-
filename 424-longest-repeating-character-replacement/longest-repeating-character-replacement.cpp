class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi = INT_MIN;
        int l =0; int r= 0;
        int maxcount =0 ;
        map<char, int> mpp;
        int n = s.size();
        while(r<n){
            mpp[s[r]]++;
            int len = r-l+1;
            maxcount = max(maxcount , mpp[s[r]]);
            int removecnt = len - maxcount;


            if(removecnt<=k){
                // r++;
                maxi = max(maxi , len);

            }
            else if(removecnt>k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }

            r++;
            cout<<maxi<<endl;
        }
        return maxi;
    }
};