/*
 
 Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	unordered_map<int, int> m;
    	for( auto& i : nums ) {
    		if( m.find(i) == m.end() ) {
    			m[i] = 0;
    		}
    		m[i] += 1;
    	}
    	for(auto& i : m) {
    		if( i.second > nums.size() / 2 ) return i.first; 
    	}
       
    }
};

int main(int argc, char* argv[]) {

} 