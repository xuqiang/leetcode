/*


Largest Number

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

*/


int compare (const string& a, const string& b){    	
	string i = a + b;
    string j = b + a;
    return i > j;
}


class Solution {
public:


    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
       	for(auto& n : nums) {
       		strs.push_back( to_string(n) );
       	}
       	sort( strs.begin(), strs.end(), compare);
       	for(auto& s : strs) {
       		res.append(s);
       	}
       	if(res[0] != '0') return res;
       	else return "0";
       	
    }
};