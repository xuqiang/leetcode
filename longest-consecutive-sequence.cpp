/*

Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive连续的 elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

1. 排序 之后 查找
2. hashmap

*/


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "common.h"

using namespace std;

// 使用hashmap记录每个元素是否被使用 对于每个元素 以这个元素为中心 向左右扩张
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> used;
        for(auto& i : nums) used[i] = false;

        int longest = 0;
    	for(auto& i : nums) {
    		if(used[i]) continue;
    		int length = 1;

    		used[i] = true;
    		for(int j = i + 1; used.find(j) != used.end(); ++j) {
    			used[j] = true;
    			length++;
    		}
    		for(int j = i - 1; used.find(j) != used.end(); --j) {
    			used[j] = true;
    			length ++;
    		}
    		longest = max(longest, length);
    	}
    	return longest;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}
