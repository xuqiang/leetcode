/*

Increasing Triplet Subsequence

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.

*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    	//  维护两个变量 数组的第一小 和  第二小 然后遍历这个数组
        int m1 = INT_MAX, m2 = INT_MAX;
        for (auto a : nums) {
            if (m1 >= a) m1 = a;
            else if (m2 >= a) m2 = a;
            else return true;
        }
        return false;
    }
};