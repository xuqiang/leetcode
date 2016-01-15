/*

Binary Tree Inorder Traversal 二叉树中序遍历

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        _traversal(root, res);
        return res;
    }
    void _traversal(TreeNode *node, vector<int>& vi) {
		if(node == nullptr) return;
		_traversal(node->left, vi);
		vi.push_back(node->val);
		_traversal(node->right, vi);
	}
};


int main(int argc, char* argv[]) {
	return 0;
}