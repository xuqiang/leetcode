/*
 
 Convert Sorted Array to Binary Search Tree

 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/


#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include "common.h"

using namespace std;


 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if( nums.size() == 0 ) 
        	return NULL;
      	return convert( nums, 0, nums.size() - 1 );
    }
    TreeNode* convert( vector<int>& nums, int l, int r ) {
    	if(l > r) return NULL;
    	int m = (l + r) / 2;
    	TreeNode* root = new TreeNode( nums[m] );
    	root->left = convert(nums, l, m - 1);
    	root->right = convert(nums, m + 1, r);
    	return root;
    }
};


int main(int argc, char* argv[]) {
	return 0;
}