/*
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int max(int a, int b) {
        return (a > b) ? (a) : (b);
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right== NULL)
            return 1;
        int left_depth = 0, right_depth = 0;
        if(root->left) 
            left_depth = maxDepth(root->left);
        if(root->right)
            right_depth = maxDepth(root->right);
        return max(left_depth, right_depth) + 1;
    }
};

int main() {
	return 0;
}
