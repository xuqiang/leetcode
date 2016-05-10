// 
// top-k-frequent-elements
// 

/*
 
 Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

 */

struct PP {
    int val;
    int count;
} te;

bool cmp(PP a,PP b) {
    return a.count > b.count;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        vector<PP> temp;
        map<int,int> mp;
        int i;
        for(i = 0;i < n;i++){
            mp[ nums[i] ]++;
        }
        for(map<int,int>::iterator it = mp.begin();it != mp.end();it++){
            te.val = it -> first;
            te.count = it -> second;
            temp.push_back(te);
        }
        sort(temp.begin(),temp.end(),cmp);
        for(i = 0;i < k;i++){
            ans.push_back(temp[i].val);
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
	return 0;
}
