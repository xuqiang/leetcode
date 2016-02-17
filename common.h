/*
常用数据结构
*/

#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct TreeNode {
 	int val;
 	TreeNode* left;
 	TreeNode* right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {  }
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) { }
};


struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
};


#endif