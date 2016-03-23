/*


Flatten Binary Tree to Linked List

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

*/


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

	TreeNode* dfs(TreeNode* root) {
		if(root == NULL) return NULL;
		TreeNode* left = root->left;
		TreeNode* right = root->right;

		root->left = NULL;
		root->right = NULL;


		TreeNode* tail = root;

		if(left != NULL) {
			tail->right = left;
			tail = dfs( left );
		}

		if(right != NULL) {
			tail->right = right;
			tail = dfs(right);
		}

		return tail;
	}

    void flatten(TreeNode* root) {
        dfs(root);
    }
};