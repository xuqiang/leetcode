/*


Maximum Product Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.


*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
		if(nums.size() == 0) return 0;

		int max_product = nums[0];
		int max_temp = nums[0];
		int min_temp = nums[0];

		for(int i = 1; i < nums.size(); ++i) {
			int a = nums[i] * max_temp;
			int b = nums[i] * min_temp;

			max_temp = max( max(a, b), nums[i] );
			min_temp = min( min(a, b), nums[i] );
			max_product = max( max_product, max_temp );
		}        
		return max_product;
    }
};

