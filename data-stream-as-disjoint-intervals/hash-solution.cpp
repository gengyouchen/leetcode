class SummaryRanges {
private:
	unordered_set<int> nums;
	unordered_map<int, pair<int, int>> start2range, end2range;
public:
	/* time: O(1), space: O(1) */
	SummaryRanges() {}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count hash table itself) */
	void addNum(int val) {
		if (nums.count(val))
			return;
		nums.insert(val);

		const auto iEnd = end2range.find(val - 1);
		const auto jStart = start2range.find(val + 1);

		if (iEnd != end2range.end() && jStart != start2range.end()) {
			const auto iStart = start2range.find(iEnd->second.first);
			const auto jEnd = end2range.find(jStart->second.second);

			end2range.erase(iEnd), start2range.erase(jStart);
			iStart->second.second = jEnd->second.second;
			jEnd->second.first = iStart->second.first;
		} else if (iEnd != end2range.end()) {
			const auto iStart = start2range.find(iEnd->second.first);

			end2range.erase(iEnd);
			iStart->second.second = val;
			end2range[val] = iStart->second;
		} else if (jStart != start2range.end()) {
			const auto jEnd = end2range.find(jStart->second.second);

			start2range.erase(jStart);
			jEnd->second.first = val;
			start2range[val] = jEnd->second;
		} else {
			start2range[val] = end2range[val] = {val, val};
		}
	}

	/* time: O(n*log(n)), space: O(1) auxiliary (i.e. does not count output itself) */
	vector<vector<int>> getIntervals() const {
		vector<vector<int>> ranges(start2range.size());
		int out = 0;
		for (const auto& it : start2range)
			ranges[out++] = {it.second.first, it.second.second};

		make_heap(ranges.begin(), ranges.end());
		sort_heap(ranges.begin(), ranges.end());
		return ranges;
	}
};
