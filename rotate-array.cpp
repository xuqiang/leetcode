/*
 rotate array

 Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

基本思路 ：

1. 旋转整个数组 [1, 2, 3, 4, 5, 6, 7] => [7, 6, 5, 4, 3, 2, 1]
2. 旋转前k个元素 [ 5, 6, 7, 4, 3, 2, 1 ]
3. 旋转后n - k 个元素 [5, 6, 7, 1, 2, 3, 4]


*/


#include <stack>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	void reverse(vector<int>& nums, int i, int j) {
		if( i >= j ) return ;
		while(i < j) {
			swap( nums[i++], nums[j--] );
		}
	}
    void rotate(vector<int>& nums, int k) {
    	if(k <= 0 || nums.size() <= 0) return;
    	int n = nums.size();
    	k %= n;
    	reverse( nums, 0, n - 1);
    	reverse(nums, 0, k - 1);
    	reverse(nums, k, n - 1);
    }
};

int main(int argc, char* argv[]) {
	return 0;
}