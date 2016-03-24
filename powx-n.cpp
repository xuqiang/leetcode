/*

Pow(x, n)



*/

double myPow(double x, int n) {
	double res = 1.0;
	while(n--) {
		res *= x;
	}
	return res;
}

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) return 1 / power(x, -n);
        return power(x, n);
    }
    double power(double x, int n) {
        if (n == 0) return 1;
        double half = power(x, n / 2);
        if (n % 2 == 0) return half * half;
        return x * half * half;
    }
};