/*


Palindrome Partitioning II


Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.


*/




class Solution{
public:
    int *minCutMat;
    vector<vector<int> > map;
    
    int IsPalindrome(string &s, int i, int j)
    {
        if(i>j) return false;
        if(map[i][j]!= -1)
            return map[i][j];
        if(i==j)
            return map[i][j]=1;
        
        if(s[i]!=s[j])
            return map[i][j]=0;
        else{
            if(j-i==1)
                return map[i][j]=1;
            else
                return map[i][j]=IsPalindrome(s,i+1,j-1);
        }
    }
    
    
    int minCut(string s) // 动态规划  d[i] = min{d[k]+1, d[k]+i-k}, 0<=k<i
    {
        int n = (int)s.length();
        if(n==0||n==1)
            return 0;
        
        vector<int> min, vtmp;
        min.clear();vtmp.clear();map.clear();
        for(int i=0; i<s.size(); i++)
        {
            min.push_back(0);
            vtmp.push_back(-1);
        }
        for(int i=0; i<s.size(); i++)
            map.push_back(vtmp);

        int tmp, ans;
        for(int inter = 1; inter<n; inter++)
        {
            if(IsPalindrome(s, 0, inter))
                min[inter]=0;
            else{
                ans = n+1;
                for(int k = 0; k < inter; k++)
                {
                    if(IsPalindrome(s, k+1, inter))
                        tmp = min[k]+1;
                    else
                        tmp = min[k] + inter - k;
                    if(tmp < ans)
                        ans = tmp;
                }
                min[inter] = ans;
            }
        }
        return min[n-1];
    }
   

};
