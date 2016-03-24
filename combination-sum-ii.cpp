/*


Combination Sum II


Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 

*/

class Solution 
{
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        vector<int> vecTmp;
        
        m_vecRet.clear();
        sort(num.begin(), num.end());
        combination(num, 0, vecTmp, target);
        
        return m_vecRet;
    }
    
private:
    void combination(const vector<int> &num, size_t idx, vector<int> &curr, int target)
    {
        if (target == 0)
        {
            m_vecRet.push_back(curr);
        }
        else
        {
            for (size_t i = idx; i < num.size(); ++i)
            {
                if (i != idx && num[i] == num[i - 1])
                {
                    continue;
                }
                
                if (target >= num[i])
                {   
                    curr.push_back(num[i]);
                    combination(num, i + 1, curr, target - num[i]);
                    curr.pop_back();
                }
            }
        }
    }
    
private:
    vector<vector<int> > m_vecRet;
};