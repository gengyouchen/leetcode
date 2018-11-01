class Solution {
private:
	template <class T, class F>
	T lowestTrue(T min, T max, F cond) {
		while (min < max) {
			auto it = min + (max - min) / 2;
			if (cond(it) == true)
				max = it;
			else
				min = it + 1;
		}
		return min;
	}
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count input & output itself) */
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		auto L = intervals.begin(), R = intervals.end();
		L = lowestTrue(L, R, [&](auto it) { return !(it->end < newInterval.start); });
		R = lowestTrue(L, R, [&](auto it) { return it->start > newInterval.end; });
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
