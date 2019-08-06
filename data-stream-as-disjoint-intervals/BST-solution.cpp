class SummaryRanges {
private:
	map<int, int> start2end;
public:
	/* time: O(1), space: O(1) */
	SummaryRanges() {}

	/* time: O(log(n)), space: O(1) auxiliary (i.e. does not count binary search tree itself) */
	void addNum(int val) {
		auto i = start2end.end(), j = start2end.upper_bound(val);
		if (j != start2end.begin())
			i = j, --i;
		if (i != start2end.end() && val <= i->second)
			return;
		if (i != start2end.end() && val != i->second + 1)
			i = start2end.end();
		if (j != start2end.end() && val != j->first - 1)
			j = start2end.end();

		if (i != start2end.end() && j != start2end.end())
			i->second = j->second, start2end.erase(j);
		else if (i != start2end.end())
			i->second = val;
		else if (j != start2end.end())
			start2end[val] = j->second, start2end.erase(j);
		else
			start2end[val] = val;
	}

	/* time: O(n), space: O(1) auxiliary (i.e. does not count output itself) */
	vector<vector<int>> getIntervals() const {
		vector<vector<int>> ranges(start2end.size());
		int out = 0;
		for (const auto& it : start2end)
			ranges[out++] = {it.first, it.second};
		return ranges;
	}
};
