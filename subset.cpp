/*

Subsets


Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


包含该元素 或者 不包含 该元素
*/



/*
 
 http://www.cnblogs.com/TenosDoIt/p/3451902.html

*/

class Solution {
private:
    vector<vector<int> >res;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        //先排序，然后dfs每个元素选或者不选，最后叶子节点就是所有解
        res.clear();
        sort(S.begin(), S.end());
        vector<int>tmpres;
        dfs(S, 0, tmpres);
        return res;
    }
    void dfs(vector<int> &S, int iend, vector<int> &tmpres)
    {
        if(iend == S.size())
            {res.push_back(tmpres); return;}
        //选择S[iend]
        tmpres.push_back(S[iend]);
        dfs(S, iend+1, tmpres);
        tmpres.pop_back();
        //不选择S[iend]
        dfs(S, iend+1, tmpres);
    }
};





class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<int> v;
        vector<vector<int> > res;
        sort(S.begin(), S.end());


        subsetsCore(S, 0, v, res);
        return res;
    }
private:
    
    void subsetsCore(vector<int> &S, int start, vector<int> &v, vector<vector<int> >& res){
        if(start == S.size()) { res.push_back(v); return;}
        vector<int> v2;
        for(vector<int>::iterator i = v.begin(); i < v.end(); v2.push_back(*(i++)));
        v.push_back(S[start]);
        subsetsCore(S, start + 1, v, res); //包含S[start]
        subsetsCore(S, start + 1, v2, res); //不包含S[start]
    }
};