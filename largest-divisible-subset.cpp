class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() ==0) return {};
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1), result;
        int curMax = 1, index = 0;
        for(int i =1; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0)
                {
                    dp[i] = max(dp[i], dp[j]+1);
                    if(dp[i] > curMax) curMax = dp[i], index = i;
                }
            }
        }
        for(int i = 0; i < nums.size(); i++)
            if(nums[index] % nums[i]==0) result.push_back(nums[i]);
        return result;
    }
};
