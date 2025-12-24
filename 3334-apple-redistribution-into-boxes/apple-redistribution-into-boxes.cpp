class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(), apple.end(),0);
        sort(capacity.begin(), capacity.end());
        reverse(capacity.begin(), capacity.end());
        int cnt =0;
        while(sum>0){
            sum-=capacity[cnt];
            cnt++;
        }
        return cnt;
    }
};