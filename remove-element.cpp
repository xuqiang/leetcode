/*
 Given an array and a value, remove all instances of that value in place and return the new length.
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.
  
  两个指针 一个遍历 nums数组 另外一个指针维护不等于val的结尾
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
 		int i = 0 ;
 		int j = 0 ;
 		for(i = 0; i < nums.size(); ++i) {
 			if(nums[i] == val) {
 				continue;
 			} else {
 				nums[j] = nums[i];
 				j++;
 			}
 		}       
 		return j;	
    }
};

int main(int argc, char* argv[]) {
	vector<int> nums = { 1, 2, 3, 2, 2, 4 };
	Solution s;
	int i = s.removeElement(nums, 2);
	for(int j = 0; j < i; ++j) {
		cout << nums[j] << " " ;
	}
	cout << endl;
	return 0;
}