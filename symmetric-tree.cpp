/*
 Symmetric Tree
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
 

检查树 是否为对称树

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
	// ----------- 递归判断 树 是否对称 -----------
	bool isSymmetric(TreeNode *root) {
		if (!root) return true;
		return isSymmetric(root->left, root->right);
	}
	bool isSymmetric(TreeNode *lt, TreeNode *rt) {
		if (!lt && !rt) return true;
		if (lt && !rt || !lt && rt || lt->val != rt->val) return false;
		return isSymmetric(lt->left, rt->right) &&isSymmetric(lt->right, rt->left);
	}
	
	bool isSymmetric(TreeNode *root) 
	{
		if (!root || !root->left && !root->right) return true;
		TreeNode *t1 = root->left, *t2 = root->right;
		if (t1 && !t2 || !t1 && t2 || t1->val != t2->val) return false;

		stack<TreeNode *> s1, s2;
		s1.push(t1), s2.push(t2);
		bool flag = false;
		while (!s1.empty() && !s2.empty())
		{
			if (!flag && (t1->left || t2->right))
			{
				s1.push(t1), s2.push(t2);
				t1 = t1->left, t2 = t2->right;
				if (t1&&!t2 || !t1&&t2 || t1->val!=t2->val) return false;
				s1.push(t1), s2.push(t2);
			}
			else if (t1->right || t2->left)
			{
				t1 = t1->right, t2 = t2->left;
				if (t1&&!t2 || !t1&&t2 || t1->val!=t2->val) return false;
				flag = false;
			}
			else
			{
				t1 = s1.top(), t2 = s2.top();
				s1.pop(), s2.pop();
				flag = true;
			}
		}
		return s1.empty() && s2.empty();
	}

};

int main(int argc, char* argv[]) {
	return 0;
}