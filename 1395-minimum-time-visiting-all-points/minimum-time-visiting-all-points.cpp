class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int cnt =0;
        for(int i =0; i<points.size()-1; i++){
            int one =abs(points[i+1][0] - points[i][0]);

            int two  = abs(points[i+1][1] - points[i][1]);

            while(one>0 && two >0){
                cnt++;
                one--; two--;

            }
            while(one>0){
                one--;
                cnt++;
            }
            while(two>0){
                two--;
                cnt++;
            }

        }
        return cnt;
    }
};