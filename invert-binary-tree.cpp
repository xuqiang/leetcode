#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x) , next(NULL) { }
};

void reverse(TreeNode* p) {
	if(p == NULL) return ;
	if(p->left == NULL && p->right == NULL) return ;
	TreeNode* i = p->left;
	p->left = p->right;
	p->right = i;
	if(p->left) reverse( p->left );
	if(p->right) reverse( p->right );
}

TreeNode* invertTree(TreeNode* root) {
	reverse(root);
	return root;
}

void printTree(TreeNode* p) {
	if(p == NULL) return ;
	vector<TreeNode*> vec;
	vec.push_back( p );
	int last = 1;
	int cur = 0;
	while(cur < vec.size()){
		last = vec.size();
		while( cur < last ) {
			cout << vec[cur]->val << " ";
			if(vec[cur]->left) vec.push_back( vec[cur]->left );
			if(vec[cur]->right) vec.push_back( vec[cur]->right );
			cur ++;
		} 
		cout << endl;
	}
	cout << endl;
}

void prinList( ListNode* p ) {
	ListNode* i = p;
	while(i) {
		cout << i->val << " ";
		i = i->next;
	}
	cout << endl;	
}

int main() {
	TreeNode* a = new TreeNode(1);	
	TreeNode* b = new TreeNode(2);	
	TreeNode* c = new TreeNode(3);	
	TreeNode* d = new TreeNode(4);	
	TreeNode* e = new TreeNode(5);	
	a->left = b;	a->right = c;
	b->left = d;	b->right = e;
	printTree(a);

	invertTree(a);
	printTree(a);
	cout << "a->left " << a->left->val << " a->right " << a->right->val << endl;
	cout << "b->left " << b->left->val << " b->right " << b->right->val << endl;

	delete a;	delete b; delete c; delete d; delete e;

	return 0;
}
