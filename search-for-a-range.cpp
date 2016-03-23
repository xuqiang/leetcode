/*

Search for a Range 



Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].


二分查找左侧 之后从右向左 查找右侧

*/


class Solution {
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> result;
        vector<int>::iterator p;
        int l,r ;
        p = find( A.begin( ), A.end( ), target );
        if (p != A.end())
            l = p - A.begin();
        else
            l = -1;
        
        r = -1;
        int len  = A.size();
        for (int i = len-1; i>=0; --i)
            if (A[i]==target) {
                r = i;
                break;
            }
        result.push_back(l);
        result.push_back(r);
        return result;
    }
};