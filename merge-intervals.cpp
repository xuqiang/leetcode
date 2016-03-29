/*


Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

先排序 后合并

*/


class Solution {
private:
    static bool comp(Interval a, Interval b) {
        return a.start < b.start;
    }
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.empty())return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            Interval &p = res.back();
            if(intervals[i].start > p.end) res.push_back(intervals[i]);
            else if(intervals[i].end > p.end) p.end = intervals[i].end;
        }
        return res;
    }
};

