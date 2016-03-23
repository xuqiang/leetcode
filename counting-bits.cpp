/*


Counting Bits

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

当一个数为2的整数幂的时候，1的个数为1，比如2（10) 和4(100)，8(1000)

在这之后就是前一个序列的数+1 比如 9(1001) = 1(1) + 8 (1) = 2

找规律


*/


class Solution {
public:
    vector<int> countBits(int num) {
       	vector<int> res = vector<int> ( num + 1, 0 );
       	int pow2 = 1;
       	int before = 1;
       	for(int i = 1; i <= num; ++i) {
       		if(i == pow2) {
       			before = res[i] = 1;
       			pow2 <<= 1;
       		} else {
       			res[i] = res[before] + 1;
       			before += 1;
       		}
       	}
       	return res;
    }
};