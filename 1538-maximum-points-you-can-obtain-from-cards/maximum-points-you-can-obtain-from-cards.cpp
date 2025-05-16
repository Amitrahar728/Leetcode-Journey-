class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum =0;
        int rsum =0;
        int maxi = 0;
        for(int i =0; i<=k-1; i++) lsum+=cardPoints[i];
        maxi = lsum;
        int n = cardPoints.size();
        int right = n-1;
        for(int i =k-1; i>=0; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum+cardPoints[right];
            right--;
            maxi = max(maxi, lsum+rsum);
        }
        return maxi;
    }
};