/*

Find Minimum in Rotated Sorted Array II

Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.


*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low < high && nums[low] >= nums[high]) {
            int mid = low + (high-low)/2;
            if(nums[mid] < nums[low])   // mid is in second part
                high = mid;
            else if(nums[mid] == nums[low])
                low ++;
            else
                low = mid+1;
        }
        return nums[low];
    }
};