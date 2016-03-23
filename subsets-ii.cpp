/*

Subsets II

Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]


http://www.cnblogs.com/TenosDoIt/p/3451902.html

*/


class Solution {
private:
    vector<vector<int> >res;
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
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
        int firstSame = iend;
        while(firstSame >=0 && S[firstSame] == S[iend])firstSame--;
        firstSame++; //firstSame是第一个和S[iend]相同数字的位置
        int sameNum = iend - firstSame;//和S[iend]相同数字的个数(除自己)
        if(sameNum == 0 ||
            (tmpres.size() >= sameNum && tmpres[tmpres.size() - sameNum] == S[iend]))
        {
            //选择S[iend]
            tmpres.push_back(S[iend]);
            dfs(S, iend+1, tmpres);
            tmpres.pop_back();
        }
        //不选择S[iend]
        dfs(S, iend+1, tmpres);
    }
};