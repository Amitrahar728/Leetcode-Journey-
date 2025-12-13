#define ll long long 
const ll mod = 1e9+7;
class Solution {
public:
    int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
    }

    int lcm(int a, int b) {
    return (a/gcd(a, b)) * b;
    }
    int nthMagicalNumber(int n, int a, int b) {
        ll low = min(a,b);
        ll high = n* 1ll * min(a,b);
        ll ans ;
        // int lc = (a*b)/ _gcd(a,b);
        int lc = lcm(a,b);
        while(low<=high){
            ll mid = low + (high-low)/2;
            ll val = mid/a + mid/b - mid/lc;
            if(val>n){
                high = mid -1;
            }
            else if (val == n) {
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans%mod;
        
    }
};