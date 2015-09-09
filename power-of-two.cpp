/*
 * 判定整数是不是2的幂
 *
 * 如果一个整数是2的幂的话，那么该数的二进制 只有一个1
 */ 

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
bool isPowerOfTwo(int n) {
    int cnt = 0;
	while( n > 0 ) {
		cnt += ( n ) & 0x01;
		n = (n >> 1);
	}
	return cnt == 1;
}
int main() {
    int n = 16;
	cout << isPowerOfTwo(n) << endl;
	
	n = 9;
	cout << isPowerOfTwo(n) << endl;


	return 0;
}
