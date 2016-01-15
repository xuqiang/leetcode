/*
 
 Populating Next Right Pointers in Each Node

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, 
the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every 
parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

   本题给定了限定条件，每棵树均为完全二叉树，对一个结点L而言其子树的结点的next指针分两种情况：

左子结点：L的右子节点（L->right）;
右子节点：L的next结点的左子结点（L->next->left），如果L本身为NULL，则该结点的next指针也指向NULL。

 */

#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include "common.h"

using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	// 递归解法  
    void connect(TreeLinkNode *root) {
        if(!root) return ;
        TreeLinkNode* left = root->left;
        TreeLinkNode* right = root->right;
        if(left) 
        	left->next = right;
        if(right) {
        	if(root->next) {
        		right->next = root->next->left;
        	} else {
        		root->next = NULL;
        	}
        }
        connect(root->left);
        connect(root->right);
    }
};

int main(int argc, char* argv[]) {
	return 0;
}