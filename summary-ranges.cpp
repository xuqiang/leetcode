/*
 * 给定有序的数组，求有序数组的连续串
 */ 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x) , next(NULL) { }
};

void printTree(TreeNode* p) {
	if(p == NULL) return ;
	vector<TreeNode*> vec;
	vec.push_back( p );
	int last = 1;
	int cur = 0;
	while(cur < vec.size()){
		last = vec.size();
		while( cur < last ) {
			cout << vec[cur]->val << " ";
			if(vec[cur]->left) vec.push_back( vec[cur]->left );
			if(vec[cur]->right) vec.push_back( vec[cur]->right );
			cur ++;
		} 
		cout << endl;
	}
	cout << endl;
}

void printList( ListNode* p ) {
	ListNode* i = p;
	while(i) {
		cout << i->val << " ";
		i = i->next;
	}
	cout << endl;	
}

vector<string> summaryRanges(vector<int>& nums) {		
	int n = nums.size();
	int i = 0;
	vector<string> res;
	while(i < n) {
		int j = 1;
		while( i + j < n && nums[i + j] - nums[i] == j ) j++;
		
		if(j == 1) res.push_back( to_string( nums[i] ) );
		else res.push_back( to_string( nums[i]) + "->" + to_string(nums[i + j - 1])  );
		
		i += j;
	}
	return res;
}

int main() {
	vector<int> vec = { 0, 1,2, 3, 5, 7, 8, 9, 10 };
	vector<string> res = summaryRanges(vec);
	for(int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
	return 0;
}
