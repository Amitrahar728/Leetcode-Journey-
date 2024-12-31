class Solution {
public:
    // int factorial (int n){
    //     if(n==0) return 0;
    //     if(n==1) return 1;
        
    //     return n*factorial(n-1);
    // }
    int trailingZeroes(int n) {
    int count = 0;
    while (n >= 5) {
        n /= 5;
        count += n;
    }
    return count;
    }
};