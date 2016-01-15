/*
Kth Smallest Element in a BST My Submissions Question

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

二叉查找树中 查找第k小的元素

中序遍历

*/

#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
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
    int kthSmallest(TreeNode* root, int k) {
       int cnt = 0;
       TreeNode* p = root;
       stack<TreeNode*> st;
       while(p != NULL || !st.empty()) {
       	if(p != NULL) {
       		st.push(p);
       		p = p->left;
       	} else {
       		p = st.top();
       		st.pop();
       		if(++cnt == k) return p->val;
       		p = p->right;
       	}
       }
    }
};


int main(int argc, char* argv[]) {
	return 0;
}

