/*

Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

class Solution {
public:
	vector<vector<int> > combine(int n, int k) {  
        vector<vector<int> > v;  
        if (k > n || k == 0) return v;  
  
        vector<int> mv;  
        comb(v, mv, n, k, 1);  
        return v;  
    }

    void comb(vector<vector<int> > &v, vector<int> &mv, int n, int k, int start)  {  
        if (mv.size() == k) {  
            v.push_back(mv);  
            return;  
        }  
  
        for (int i = start; i <= n; i++)  {  
            mv.push_back(i);  
            comb(v, mv, n, k, i + 1); 
            mv.pop_back();  
        }  
    }  

};