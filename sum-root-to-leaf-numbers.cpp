/*

Sum Root to Leaf Numbers


Given a binary tree containing digits from 0-9 only, each root-to-leaf path could 
represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.


For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

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
    int sumNumbers(TreeNode* root) {
        sum(root, 0);
    }

    int sum( TreeNode* r, int path = 0 ) {
    	if(r == nullptr) 
    		return 0;
    	if( r->left == nullptr && r->right == nullptr ) {
    		return 10 * path  + r->val;
    	}
    	return sum( r->left, 10 * path + r->val ) + sum( r->right, 10 * path + r->val );
    }

};


int main(int argc, char* argv[]) {
	return 0;
}