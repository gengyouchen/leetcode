class Solution {
public:
	/* time: O(n*log(n)), space: O(1) auxiliary (i.e. does not count input itself) */
	bool canAttendMeetings(vector<Interval>& intervals) {
		if (intervals.size() < 2)
			return true;

		auto comp = [](const auto& a, const auto& b) {
			if (a.start != b.start)
				return a.start < b.start;
			else
				return a.end < b.end;
		};
		make_heap(intervals.begin(), intervals.end(), comp);
		sort_heap(intervals.begin(), intervals.end(), comp);

		for (auto it = intervals.begin() + 1; it != intervals.end(); ++it) {
			if ((it - 1)->end > it->start)
				return false;
		}
		return true;
	}
};
