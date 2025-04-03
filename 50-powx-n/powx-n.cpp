class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;  // Any number raised to 0 is 1
        if (x == 1) return 1;  // Optimization for x = 1

        long long exp = n;  // Use long long to handle INT_MIN case
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double result = 1;
        while (exp) {
            if (exp % 2) result *= x; // If odd, multiply x once
            x *= x;                   // Square the base
            exp /= 2;                  // Divide exponent by 2
        }
        
        return result;
    }
};