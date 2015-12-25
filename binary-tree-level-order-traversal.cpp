/*
 Binary Tree Level Order Traversal
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

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
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        vector<int> lev;
        if(root == NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        while(true) {
        	TreeNode* cur = que.front();
        	que.pop();

        	if(cur == NULL) {
        		res.push_back(lev);
        		lev.clear();
        		if(que.empty()) {
        			break;
        		}
        		que.push(NULL);
        	} else {
        		lev.push_back( cur->val );
        		if(cur->left) {
        			que.push(cur->left);
        		} 
        		if(cur->right) {
        			que.push( cur->right );
        		}
        	}
        }
        return res; 
    }
};

int main(int argc, char* argv[]) {
	return 0;
}