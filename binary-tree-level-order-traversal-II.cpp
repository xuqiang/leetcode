/*

Binary Tree Level Order Traversal II

类似题目 Binary Tree Level Order Traversal 最终需要把res reverse下


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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        reverse(res.begin(), res.end());
        return res; 
    }
};

int main(int argc, char* argv[]) {
	return 0;
}
