/*

Range Sum Query - Mutable

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.

线段树

*/


struct SegmentTreeNode {
    int s, e, sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int _s, int _e) : s(_s), e(_e), sum(0), left(NULL), right(NULL) {}
};

class SegmentTree {
public:
    SegmentTree(vector<int>& nums) {
        int n = nums.size();
        root = buildST(nums, 0, n - 1);
    }

    void update(int i, int val) {
        update(root, i, val);
    }

    int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }
private:
    SegmentTreeNode* root;
    SegmentTreeNode* buildST(vector<int>& nums, int s, int e) {
        if (s > e) return NULL;
        else {
            SegmentTreeNode* res = new SegmentTreeNode(s, e);
            if (s == e) res->sum = nums[s];
            else {
                int m = s + (e - s) / 2;
                res->left = buildST(nums, s, m);
                res->right = buildST(nums, m + 1, e);
                res->sum = res->left->sum + res->right->sum;
            }
            return res;
        }
    }
    void update(SegmentTreeNode* root, int i, int val) {
        if (root->s == root->e) root->sum = val;
        else {
            int m = root->s + (root->e - root->s) / 2;
            if (i <= m) update(root->left, i, val);
            else update(root->right, i, val);
            root->sum = root->left->sum + root->right->sum;
        }
    }
    int sumRange(SegmentTreeNode* root, int s, int e) {
        if (root->s == s && root->e == e) return root->sum;
        else {
            int m = root->s + (root->e - root->s) / 2;
            if (e <= m) return sumRange(root->left, s, e);
            else if (s >= m + 1) return sumRange(root->right, s, e);
            else return sumRange(root->left, s, m) + sumRange(root->right, m + 1, e);
        }
    }
};

class NumArray {
public:
    NumArray(vector<int>& nums) {
        st = new SegmentTree(nums);
    }

    void update(int i, int val) {
        st->update(i, val);
    }

    int sumRange(int i, int j) {
        return st->sumRange(i, j);
    }
private:
    SegmentTree* st;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);