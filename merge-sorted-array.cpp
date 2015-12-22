/*

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
The number of elements initialized in nums1 and nums2 are m and n respectively.

由于数组是已经排序的，技巧是从结尾开始归并
 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {	
 		int i = m + n - 1;
        int j = m - 1;
        int k = n - 1;

        while(i >= 0) {
            if(j >= 0 && k >= 0) {
                if(A[j] > B[k]) {
                    A[i] = A[j];
                    j--;
                } else {
                    A[i] = B[k];
                    k--;
                }
            } else if(j >= 0) {
                A[i] = A[j];
                j--;
            } else if(k >= 0) {
                A[i] = B[k];
                k--;
            }
            i--;
        }
    }    
};


int main(int argc, char* argv[]) {
	vector<int> nums1(10);
	nums1[0] = 1;
	nums1[1] = 2;
	nums1[2] = 3;

	vector<int> nums2 = { 2, 3, 4, 5 };
	cout << nums2.size() << endl;


	Solution s;
	s.merge(nums1, 3, nums2, 4);
	for(auto& i : nums1) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}