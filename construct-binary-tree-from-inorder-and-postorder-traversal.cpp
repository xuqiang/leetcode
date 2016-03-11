/*

Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Subscribe to see which companies asked this question


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
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}

	TreeNode *buildTree(vector<int> &inorder, int s0, int e0, vector<int> &postorder, int s1, int e1) {
		if (s0 > e0 || s1 > e1)
			return NULL;

		int rootval = postorder[e1];
		TreeNode * root = new TreeNode(rootval);

		int i,mid;
		for (i = s0; i <= e0; ++i) {
			if (inorder[i] == rootval) {
				mid = i;
				break;
			}
		}

		int leftnum = mid - s0;
		root->left = buildTree(inorder, s0, mid - 1, postorder, s1, s1 + leftnum - 1);
		root->right = buildTree(inorder, mid + 1, e0, postorder, s1 + leftnum, e1 - 1);
		return root;
	}
};