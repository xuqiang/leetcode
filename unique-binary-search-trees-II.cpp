/*
 
 Unique Binary Search Trees II

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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
    private:
        vector<vector<vector<TreeNode*>>> cache;
    public:
        vector<TreeNode*> generateTrees(int n){
            if(n==0) return vector<TreeNode*>{};
            cache = vector<vector<vector<TreeNode*>>>(n + 1, vector<vector<TreeNode*>>(n + 1, vector<TreeNode*>{}));
            return generateTrees(1, n);
        }
        vector<TreeNode*> generateTrees(int start, int end){
            if (start >= 0 && start<cache.size() && end >= 0 && end<cache[0].size() && !cache[start][end].empty())
                return cache[start][end];
            vector<TreeNode*> cur;
            if (start > end){
                return vector<TreeNode*>{nullptr};
            }
            for (int i = start; i <= end; i++){

                vector<TreeNode*> left = generateTrees(start, i - 1);
                vector<TreeNode*> right = generateTrees(i + 1, end);
                for (auto l : left){
                    for (auto r : right){
                        TreeNode* root = new TreeNode(i);
                        root->left = l;
                        root->right = r;
                        cur.push_back(root);
                    }
                }
            }
            cache[start][end] = cur;
            return cur;
        }
    };

