/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

主要问题 需要防止整数溢出

 */ 


#include <iostream>
#include <string>

using namespace std;

int reverse(int x) {
	bool ispositive = true;
	// 这里需要使用long long类型，不然 y = y * -1 无法计算
	long long y = x;
	if(y < 0) { 
		ispositive = false;
		y = -1 * y;
	}

	long long res = 0;
	while(y) {
		res = res * 10 + y % 10;
		cout << res << endl;
		y /= 10;
	}
	if(res > INT_MAX) return 0;
	if(ispositive) return res;
	else return res * -1;
}

int main() {
	int x = -2147483648;
	// int x = -123;
	cout << x << " " << x * -1 << " " << reverse(x) << endl;

	return 0;
}
