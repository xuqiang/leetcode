/*


Single Number III

Given an array of numbers nums, in which exactly two elements appear only once and 
all the other elements appear exactly twice. Find the two elements that appear only once.

两个元素出现一次 找到这两个元素

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?


假设我们要找的这两个数为 a, b, 而 x = a ^ b。

首先，a 肯定不等于 b，那么说明它们的二进制位一定是不完全相同的，所以 x 肯定不为 0。

也就是说，a 与 b 一定存在“某一位”，使得在它们中的某个数中是 0，而在另一个数中是 1，这是他们之间的一个差别。

我们可不可以利用这个差别来把这两个数从 x 中揪出来呢？

是可以的。

 

利用这个差别，我们可以将整个 nums 集合分成两个集合。一个集合中是这 “某一位” 为 0 的在nums中的所有数，
假设为集合 A。而另一个集合是这 “某一位” 为 1 的在nums中的所有数。假设 a 的这 “某一位” 是 0 ，b 的 
这个“某一位”是1，那么显然 a 在集合 A 中，b 在集合 B 中，这样问题就完全转化成了与 I 一样的两个子问题，
于是可以得解。

*/


class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def singleNumber(self, nums):
        diff = 0
        for e in nums:
            diff ^= e
        diff &= -diff
        ans = [0, 0]
        for e in nums:
            if diff & e != 0:
                ans[0] ^= e
            else:
                ans[1] ^= e
        return ans