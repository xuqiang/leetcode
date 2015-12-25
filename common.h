/*
常用数据结构
*/

#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>

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


#endif