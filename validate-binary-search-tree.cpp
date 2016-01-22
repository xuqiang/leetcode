/*

Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

*/ 

#include <string>
#include <unordered_map>
#include <vector>
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
    bool isValidBST(TreeNode* root) {
    	/*
    	中序遍历
    	*/
        if(root == nullptr) {
        	return true;
        }
        stack<TreeNode*> ns;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;

        while(true) {
        	while( cur != nullptr ) {
        		ns.push( cur );
        		cur = cur->left;
        	}
        	if(ns.empty()) {
        		break;
        	}

        	cur = ns.top();
        	ns.pop();

        	if(pre != nullptr && pre->val >= cur->val) {
        		return false;
        	}

        	pre = cur;
        	cur = cur->right;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}