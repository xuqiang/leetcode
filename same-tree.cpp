/*
 
 Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.


递归判断两棵树是否相同



*/


#include "common.h"

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) 
        	return true;
        if( (p == nullptr && q != nullptr) || ( p != nullptr && q == nullptr ) ) 
        	return false;
        if(p->val != q->val) 
        	return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, char* argv[]) {
	return 0;
}