/*

Binary Tree Preorder Traversal

二叉树前序遍历 非递归

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3]

*/

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <string>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> nstack;
        nstack.push(root);
        while( !nstack.empty() ) {
        	TreeNode* p = nstack.top();
        	res.push_back( p->val );
        	nstack.pop();

        	if( p->right ) 
        		nstack.push(p->right);
        	if(p->left) 
        		nstack.push(  p->left );
        }
        return res;
    }
};



int main(int argc, char* argv[]) {

	return 0;
}