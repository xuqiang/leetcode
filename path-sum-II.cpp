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

void mkres(int* arr, int len, int sum, vector<vector<int> >& res) {
	int n = 0;
	vector<int> vec;
	for(int i = 0; i < len; ++i) {
		n += arr[i];
		vec.push_back( arr[i] );
	}
	if(n == sum)
		res.push_back(vec);
}

void func(TreeNode* p,  int* path, int index, int sum,  vector<vector<int> >& res) {
	if( p == NULL ) 
		return ;
	path[ index ] = p->val;
	index++;
	if(p->left == NULL && p->right == NULL) {
		mkres( path, index, sum, res );
	} else {
		func( p->left, path, index, sum, res );
		func( p->right, path, index, sum, res );
	}
}

vector<vector<int> > pathSum(TreeNode* root, int sum) {
	vector<vector<int> > res;
	if(root == NULL) return res;
	int path[1024];
	func( root, path, 0, sum, res );
	return res;
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


	vector< vector<int> > res = pathSum(a, 8);
	for(int i = 0; i < res.size(); ++i){
		for(int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	delete a , b , c, d, e;

	return 0;

}
