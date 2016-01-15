/*

Sort Colors

Given an array with n objects colored red, white or blue, sort them so that objects of the same color
 are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

计数排序

*/

#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include "common.h"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[3] = { 0, 0, 0 };
        for(int i = 0; i < nums.size(); ++i) {
        	counts[ nums[i] ] ++;
        }
        int index = 0;
        for(int i = 0; i < 3; ++i) {
        	for(int j = 0; j < counts[i]; ++j) {
        		nums[index++] = i;
        	}
        }
        return ;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}