/*


Count of Range Sum


Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.

sum[i] = nums[0] + nums[1] + ... + nums[i]，对于某个i来说，只有那些满足 lower <= sum[i] - sum[j] <= upper 的j能形成一个区间[j, i]满足题意，那么我们的目标就是来找到有多少个这样的j (0 =< j < i) 满足 sum[i] - upper =< sum[j] <= sum[i] - lower，我们可以用C++中由红黑树实现的multiset数据结构可以对其中数据排序，然后用upperbound和lowerbound来找临界值。lower_bound是找数组中第一个不小于给定值的数(包括等于情况)，而upper_bound是找数组中第一个大于给定值的数，那么两者相减，就是j的个数


*/

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res = 0;
        long long sum = 0;
        multiset<long long> sums;
        sums.insert(0);
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res += distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower));
            sums.insert(sum);
        }
        return res;
    }        
};