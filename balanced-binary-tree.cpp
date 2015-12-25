/*
Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

确定二叉树 是否是平衡二叉树

计算树的高度 判断树是否平衡

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
	int depth(TreeNode* root) {
		if(root == nullptr) return 0;
		return 1 + max( depth(root->left), depth(root->right) );
	}

    bool isBalanced(TreeNode* root) {
  		if(root == nullptr) return true;
  		if( fabs( depth(root->left) - depth(root->right) ) > 1 ) 
  			return false;
  		return isBalanced(root->left) && isBalanced(root->right);
    }
};

int main(int argc, char* argv[]) {
	return 0;
}