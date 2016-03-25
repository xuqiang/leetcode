/*


Next Permutation


Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

对当前排列从后向前扫描，找到一对为升序的相邻元素，记为i和j（i < j）。如果不存在这样一对为升序的相邻元素，则所有排列均已找到，算法结束；否则，重新对当前排列从后向前扫描，找到第一个大于i的元素k，交换i和k，然后对从j开始到结束的子序列反转，则此时得到的新排列就为下一个字典序排列。这种方式实现得到的所有排列是按字典序有序的，


*/


class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() < 2) return;
        int i, k;
        for (i = num.size() - 2; i >= 0; --i) if (num[i] < num[i+1]) break;
        for (k = num.size() - 1; k > i; --k) if (num[i] < num[k]) break;
        if (i >= 0) swap(num[i], num[k]);
        reverse(num.begin() + i + 1, num.end());
    }
};