/*

Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.


*/

#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto& i : nums) {
        	if(s.find(i) != s.end()) return true;
        	else 
        		s.insert(i);
        }
        return false;
    }
};

int main() {
	return 0;
}