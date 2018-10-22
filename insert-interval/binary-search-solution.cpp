class Solution {
private:
	template <class I, class F>
	I findFirstTrue(I first, I last, F cond) {
		while (first != last) {
			I mid = first + (last - first) / 2;
			if (cond(mid))
				last = mid;
			else
				first = mid + 1;
		}
		return first;
	}
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		auto L = intervals.begin(), R = intervals.end();
		L = findFirstTrue(L, R, [&](auto it) { return !(it->end < newInterval.start); });
		R = findFirstTrue(L, R, [&](auto it) { return it->start > newInterval.end; });
		if (L == R)
			intervals.insert(L, newInterval);
		else {
			newInterval.start = min(newInterval.start, L->start);
			newInterval.end = max(newInterval.end, (R - 1)->end);

			*L = newInterval;
			intervals.erase(L + 1, R);
		}
		return intervals;
	}
};
