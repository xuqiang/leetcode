#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val (x), left(NULL), right(NULL) {  }
};

void print(int* arr, int len) {
	for(int i = 0; i < len; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void mkstr(int* arr, int len, vector<string>& paths) {
	string str;
	for(int i = 0; i < len; ++i) {
		str.append( std::to_string(arr[i]) );
		if(i != len - 1) 
			str.append( "->" );
	}
	paths.push_back(str);
}

void func(TreeNode* p,  int* path, int index, vector<string>& paths) {
	if( p == NULL ) 
		return ;
	path[ index ] = p->val;
	index++;
	if(p->left == NULL && p->right == NULL) {
		mkstr( path, index, paths );
	} else {
		func( p->left, path, index, paths );
		func( p->right, path, index, paths );
	}
}

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> paths;
	if(root == NULL) return paths;
	int path[1024];
	func( root, path, 0, paths);
	return paths;
}

int main() {
/*	string str = "1->2->4";
	str.resize(str.size() - 3); 
	cout << str << endl; 
*/	
	TreeNode* a = new TreeNode(1);
	TreeNode* b = new TreeNode(2);
	TreeNode* c = new TreeNode(3);
	TreeNode* d = new TreeNode(4);
	TreeNode* e = new TreeNode(5);
	
	a->left = b;	a->right = c;
	b->left = d;	b->right = e;


	vector<string> res = binaryTreePaths(a);
	for(int i = 0; i < res.size(); ++i){
		cout <<  res[i] << endl;
	}

	delete a , b , c, d, e;

	return 0;

}
