/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest 
path from the root node down to the nearest leaf node.
 
 寻找树的最短路径

*/

#include <iostream>
#include <vector>
#include <string>
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
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode( int x ) : val(x), left(NULL), right(NULL) {  }
};

TreeNode* mkTree( ) {
	TreeNode* a = new TreeNode( 1 );
	TreeNode* b = new TreeNode( 2 );
	TreeNode* c = new TreeNode( 3 );
	TreeNode* d = new TreeNode( 4 );

	a->left = b;	a->right = c;
	c->right = d;
}

void desTree(TreeNode* r) {
	if(r->left == NULL || r->right == NULL) {
		delete r;
		return ;
	}
	if(r->left) {
		desTree(r->left);
	}
	if(r->right) {
		desTree(r->right);
	}
	delete r;
}

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) {
        	return 0;
        }
        if(root->left == NULL) {
        	return minDepth(root->right) + 1;
        }
        if(root->right == NULL) {
        	return minDepth(root->left) + 1;
        }
        return min( minDepth(root->left), minDepth(root->right) ) + 1;
    }
};

int main() {
	return 0;
}