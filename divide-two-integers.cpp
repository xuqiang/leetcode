/*

Divide Two Integers


Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

*/


class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        long m = labs(dividend), n = labs(divisor), res = 0;
        long sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if (n == 1) return m * sign;
        while (m >= n) {
            long k = n;
            int i = 0;
            while (k <= m) {
                m -= k;
                k <<= 1;
                res += 1 << i;
                ++i;
            }
        }
        return (res * sign);
    }
};