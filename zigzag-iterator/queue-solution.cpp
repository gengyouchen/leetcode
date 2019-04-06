class ZigzagIterator {
private:
	typedef vector<int>::const_iterator I;
	typedef pair<I, I> PII;
	queue<PII> q;
public:
	/*
	 * time: O(k), space: O(1) auxiliary (i.e. does not count iterator queue itself),
	 * where k = # of input vectors = 2
	 */
	ZigzagIterator(const vector<int>& v1, const vector<int>& v2) {
		if (v1.begin() != v1.end())
			q.emplace(v1.begin(), v1.end());
		if (v2.begin() != v2.end())
			q.emplace(v2.begin(), v2.end());
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count iterator queue itself) */
	int next() {
		PII curr = q.front();
		q.pop();
		const int val = *curr.first++;
		if (curr.first != curr.second)
			q.push(curr);
		return val;
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count iterator queue itself) */
	bool hasNext() const {
		return !q.empty();
	}
};
