class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0;
        int r = people.size()-1;
        int boat =0;
        while(l<=r){
            int rem = limit - people[r];
            if(rem ==0){
                r--;
                boat++;
            }
            else {
                if(people[l]<=rem){
                    l++;
                    r--;
                    boat++;
                }
                else{
                    r--;
                    boat++;
                }
            }

        }
        return boat;
    }
};