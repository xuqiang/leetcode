/*

Count Complete Tree Nodes


Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.


对于完全二叉树，去掉最后一层，就是一棵满二叉树，我们知道高度为 h 的满二叉树结点的个数为 2^h - 1 个，所以要知道一棵完全二叉树的结点个数，只需知道最后一层有多少个结点。而完全二叉树最后一层结点是从左至右连续的，所以我们可以依次给它们编一个号，然后二分搜索最后一个叶子结点。我是这样编号的，假设最后一层在 h 层，那么一共有 2^(h-1) 个结点，一共需要 h - 1 位来编号，从根结点出发，向左子树走编号为 0， 向右子树走编号为 1，那么最后一层的编号正好从0 ~ 2^(h-1) - 1。复杂度为 O(h*log(2^(h-1))) = O(h^2)


参考这个 http://www.cnblogs.com/easonliu/p/4556487.html
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
    bool isOK(TreeNode *root, int h, int v) {
        TreeNode *p = root;
        for (int i = h - 2; i >= 0; --i) {
            if (v & (1 << i)) p = p->right;
            else p = p->left;
        }
        return p != NULL;
    }
    
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode *p = root;
        int h = 0;
        while (p != NULL) {
            p = p->left;
            ++h;
        }
        int l = 0, r = (1 << (h - 1)) - 1, m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (isOK(root, h, m)) l = m + 1;
            else r = m - 1;
        }
        return (1 << (h - 1)) + r;
    }
};