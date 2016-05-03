/*

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

技巧：  hashmap

*/ 

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    
    vector<int> twoSum(vector<int> &numbers, int target) {
    	vector<int> res;
		if(numbers.size() <= 1) return res;
		unordered_map<int, int> m;
		for(int i = 0; i < numbers.size(); ++i) {
			m[ numbers[i] ] = i;
		}
		for(int i = 0; i < numbers.size(); ++i) {
			int rest = target - numbers[i];
			if( m.find(rest) != m.end() ) {
				int j = m[rest];
				if(i == j) continue;
				if( i > j ) {
					res.push_back( j + 1 );
					res.push_back( i + 1);
				}  else {
					res.push_back( i + 1 );
					res.push_back( j + 1 );
				}
				return res;
			}
 		}

    }
};

int main(int argc, char* argv[]) {
	vector<int> numbers = { 3, 2, 4 };
	Solution s;
	vector<int> res = s.twoSum( numbers, 6 );
	for(auto& i : res) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}