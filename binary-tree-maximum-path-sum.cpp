/*

Binary Tree Maximum Path Sum

Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

*/




class Solution {
public:
    int calLen(TreeNode *root, int &len) {
        if (root == NULL) {
            len = 0;
            return 0;
        }
        
        if (root->left == NULL && root->right == NULL) {
            len = root->val;
            return root->val;
        }
        
        int leftPath, rightPath;
        int leftLen;
        if (root->left)
            leftLen = calLen(root->left, leftPath);
        else {
            leftLen = INT_MIN;
            leftPath = 0;
        }
        
        int rightLen;
        if (root->right)
            rightLen = calLen(root->right, rightPath);
        else {
            rightLen = INT_MIN;
            rightPath = 0;
        }
        
        len = max(max(leftPath, rightPath) + root->val, root->val);
        int maxLen = max(root->val, max(leftPath + rightPath + root->val, 
            max(leftPath + root->val, rightPath + root->val)));
        
        return max(max(leftLen, rightLen), maxLen);
    }
    
    int maxPathSum(TreeNode *root) {
        int len;
        return calLen(root, len);
    }
};


