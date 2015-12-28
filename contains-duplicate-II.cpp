/*

Contains Duplicate II

Given an array of integers and an integer k, find out whether there are two distinct indices i and j 
in the array such that nums[i] = nums[j] and the difference 数组下标 between i and j is at most k.

使用set来存储k个数据

*/

#include <stack>
#include <iostream>
#include <string>
#include "common.h"

using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        if(k <= 0 || len <= 0) {
            return false;
        }
        set<int> s;
        for(int i = 0; i < len; i++) {
            if(s.size() > k){
                s.erase(nums[i - k - 1]);
            }
            if(s.find(nums[i]) != s.end()){
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};


int main(int argc, char* argv[]) {
	return 0;
}