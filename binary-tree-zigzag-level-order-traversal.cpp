/*
 
 binary tree zigzag level order traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

层次遍历 按照 层反转 

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

#include <string>
#include <iostream>
 #include <vector>
 

using namespace std;


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Node {
    TreeNode *node;
    int level;
    Node(){}
    Node(TreeNode *n, int l):node(n), level(l){}
};

class Solution {
private:
    vector<vector<int> > ret;
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        
        if (root == NULL)
            return ret;
        
        queue<Node> q;
        
        q.push(Node(root, 0));
        
        int curLevel = -1;
        
        vector<int> a;
        
        while(!q.empty())
        {
            Node node = q.front();
            
            if (node.node->left)
                q.push(Node(node.node->left, node.level + 1));
            
            if (node.node->right)
                q.push(Node(node.node->right, node.level + 1));
                
            if (curLevel != node.level)
            {
                if (curLevel != -1)
                {
                    if (curLevel % 2 == 1)
                        reverse(a.begin(), a.end());
                        
                    ret.push_back(a);
                }
                a.clear();
                curLevel = node.level;
            }
            a.push_back(node.node->val);
            q.pop();
        }
        
        if (curLevel % 2 == 1)
            reverse(a.begin(), a.end());
            
        ret.push_back(a);
        
        return ret;
    }
};


int main(int argc, char* argv[])  {

  return 0;

}
