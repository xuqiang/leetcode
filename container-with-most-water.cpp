/*

Container With Most Water

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate 
(i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the 
most water.

Note: You may not slant the container.


 设置两个指针i, j, 一头一尾, 相向而行. 假设i指向的挡板较低, j指向的挡板较高(height[i] < height[j]).
    下一步移动哪个指针?
    -- 若移动j, 无论height[j-1]是何种高度, 形成的面积都小于之前的面积.
    -- 若移动i, 若height[i+1] <= height[i], 面积一定缩小; 但若height[i+1] > height[i], 面积则有可能增大.
    综上, 应该移动指向较低挡板的那个指针.



*/

class Solution {
public:
   int maxArea(vector<int>& height) {
        int max = 0, area = 0, l = 0, r = 0;
        int n = height.size();
        if (n < 2)
            return max;

        int left = 0, right = n - 1;

        while (left < right) {
            l = height[left];
            r = height[right];
            area = min(l, r) * (right - left);
            if (max < area)
                max = area;

            if (l < r) {
                left++;
                while (left < right && height[left] <= l)
                    left++;
            } else {
                right--;
                while (left < right && height[right] <= r)
                    right--;
            }
        }

        return max;
    }
};