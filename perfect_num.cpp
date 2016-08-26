#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

double factor(int n) {
    double res = 1.0;
    for(int i = 1; i <= n; ++i) {
        res *= i;
    }
    return res;
}

int comb(int n, int k) {
	if (k <= 0) return 1;
    double res = factor(n) / ( factor(k) * factor(n - k) );
    return int(res);
}

int get_bit_num(int n) {
    int i= 0;
    while((n = (n >> 1)) > 0) i++;
    return i + 1;
}

bool is_square_num(int m){
    double x = sqrt(m);
    if (floor(x) == x) {
	        return true;
	    }
    return false;
}

// 基本思路：
// 对于每一位 如果该位是1 ，分两类 改位取1 或者不取1
// 如果不取1 这是剩余位数考虑排列组合
// 如果取1 问题可以继续转化成子问题
// 最后问题可以归结为最后一位 如果是1 那么可以取0/1 如果是0 只能取0
int get_perfect_num(int n) {
	if(n == 1) return 1;
	// 假设整数是32位
	int square_nums[] = { 1, 4, 8, 16, 25 };
	int len = sizeof( square_nums ) / sizeof(int);
	int res = 0;
	int bit_num = get_bit_num(n);
	int cur_bit_one_num = 0;
	for(int i = bit_num; i > 1; i--) {
		if( ( n & ( 1 << (i - 1)  ) ) > 0 ) {
			int left = i - 1;
			for(int j = 0; j < len; ++j) {
				// 还需要k个1 就可以成为平方数
				int k = square_nums[j] - cur_bit_one_num;
				if(k >= 0 && k <= left) {
					res += comb( left, k );
				}
			}
			cur_bit_one_num ++;
		}	
	}
	if( is_square_num(cur_bit_one_num) ) res++;
	if( n & 0x1 > 0 ) {
		cur_bit_one_num++;
		if( is_square_num(cur_bit_one_num) ) res++;
	} 
	return res;
}

int main() {
	for(int i = 0; i < 26; ++i) {
		cout << i << " " << get_perfect_num(i)	<< endl;
		cout << ">>>>>>>>>>>>>>>>>>" << endl;
	}
	return 0;
};
