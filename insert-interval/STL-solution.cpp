class Solution {
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		auto p = equal_range(intervals.begin(), intervals.end(), newInterval, [](auto a, auto b) {
			return a.end < b.start;
		});
		if (p.first == p.second)
			intervals.insert(p.first, newInterval);
		else {
			newInterval.start = min(newInterval.start, p.first->start);
			newInterval.end = max(newInterval.end, (p.second - 1)->end);

			*(p.first) = newInterval;
			intervals.erase(p.first + 1, p.second);
		}
		return intervals;
	}
};
