/*



Insert Interval


Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].



*/

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            if (intervals[i].end < newInterval.start)
                res.push_back(intervals[i]);
            else if (newInterval.end < intervals[i].start) {
                res.push_back(newInterval);
                for (int j = i; j < n; j++)
                    res.push_back(intervals[j]);
                return res;
            }
            else newInterval = merge(intervals[i], newInterval);
        }
        res.push_back(newInterval);
        return res;
    }
private:
    Interval merge(Interval interval1, Interval interval2) {
        int start = min(interval1.start, interval2.start);
        int end = max(interval1.end, interval2.end);
        return Interval(start, end);
    }
};