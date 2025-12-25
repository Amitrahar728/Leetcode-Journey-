class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long  timer =0;
        long long start = happiness.size()-k;
        sort(happiness.begin(), happiness.end());
        long long sum =0;
        for(long long i = happiness.size()-1; i>=start; i--){
            if(happiness[i]-timer <=0 ){
                break;
            }

            sum+=happiness[i]-timer;
           
            timer++;
            // cout<<sum<<endl;


        }
        return sum;
    }
};