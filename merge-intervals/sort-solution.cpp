class Solution {
public:
	/* time: O(n*log(n)), space: O(1) auxiliary (i.e. does not count input & output itself) */
	vector<Interval> merge(vector<Interval>& intervals) {
		auto comp = [](const auto& a, const auto& b) {
			if (a.start != b.start)
				return a.start < b.start;
			else
				return a.end < b.end;
		};
		make_heap(intervals.begin(), intervals.end(), comp);
		sort_heap(intervals.begin(), intervals.end(), comp);

		vector<Interval> ans;
		for (auto it = intervals.begin(); it != intervals.end(); ++it)
			if (ans.empty() || ans.back().end < it->start)
				ans.push_back(*it);
			else
				ans.back().end = max(ans.back().end, it->end);
		return ans;
	}
};
