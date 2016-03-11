/*

Construct Binary Tree from Preorder and Inorder Traversal

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
    typedef vector<int>::iterator Iter;
    TreeNode *buildTreeRecur(Iter istart, Iter iend, Iter pstart, Iter pend)
    {
        if(istart == iend)return NULL;
        int rootval = *pstart;
        Iter iterroot = find(istart, iend, rootval);
        TreeNode *res = new TreeNode(rootval);
        res->left = buildTreeRecur(istart, iterroot, pstart + 1, pstart + 1 + (iterroot - istart));
        res->right = buildTreeRecur(iterroot + 1, iend, pstart + 1 + (iterroot - istart), pend);
        return res;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return buildTreeRecur(inorder.begin(), inorder.end(), preorder.begin(), preorder.end());
    }
};