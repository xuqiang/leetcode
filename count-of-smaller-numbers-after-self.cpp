/*
Count of Smaller Numbers After Self

You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].

可以使用 树状数组(Binary Indexed Tree (Fenwick tree)) 或者 先段数 来求解

*/

public class Solution {
    private int lowbit(int x) {
            return x&(-x);
    }
    
    private void add(int[] bit, int i, int val) {
        for (; i < bit.length; i += lowbit(i)) bit[i] += val;
    }

    private int query(int[] bit, int i) {
        int ans = 0;
        for (; i > 0; i -= lowbit(i)) ans += bit[i];
        return ans;
    }

    public List<Integer> countSmaller(int[] nums) {
        int[] tmp = nums.clone();
        Arrays.sort(tmp);
        for (int i = 0; i < nums.length; i++) nums[i] = Arrays.binarySearch(tmp, nums[i]);
        int[] bit = new int[nums.length];
        Integer[] ans = new Integer[nums.length];
        for (int i = nums.length - 1; i >= 0; i--) {
            ans[i] = query(bit, nums[i]);
            add(bit, nums[i]+1, 1);
        }
        return Arrays.asList(ans);
    }
}