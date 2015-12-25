/*

Climbing Stairs

*/

#include <vector>
#include <iostream>
#include "common.h"

using namespace std;


class Solution {
public:
	int climbStairs(int n) {
		vector<int> res(n + 1);
		res[0] = 1;
		res[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			res[i] = res[i - 1] + res[i - 2];
		}
		return res[n];
	}
};

int main(int argc, char* argv[]) {
	return 0;
}