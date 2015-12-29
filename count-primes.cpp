/*

Count Primes

查找小于n的素数的个数 算法 https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

*/


#include <iostream>
#include <vector>
#include <string>
#include "common.h"

using namespace std;


class Solution {
public:
    int countPrimes(int n) {
    	if(n <= 2) return 0;
       bool* p = new bool[n];
       memset(p, true, sizeof(bool) * n);
       for(int i = 2; i * i < n; ++i) {
       	if(p[i]) {
       		for(int j = 2; j * i < n ; ++j) {
       			p[i * j] = false;
       		}
       	}
       }

       int cnt = 0;
       for(int i = 2; i < n ; ++i) {
       	if(p[i])
       		cnt ++;
       }

       delete []p;
       return cnt;

    }
};

int main(int argc, char* argv[]) {
	Solution s;
	cout << s.countPrimes(1) << endl;
	cout << s.countPrimes(2) << endl;
	cout << s.countPrimes(10) << endl;
	return 0;
}