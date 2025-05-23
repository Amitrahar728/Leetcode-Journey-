class Solution {
public:
    
    int tribonacci(int n) {
       if (n <= 2)
        return (n > 0) ? 1 : 0;  

    int a = 0, b = 1, c = 1;
    for (int i = 3; i <= n; ++i) {
        int next_term = a + b + c;
        a = b;
        b = c;
        c = next_term;
    }
    return c;
    }
};