class NestedIterator {
private:
	using I = vector<NestedInteger>::const_iterator;
	stack<pair<I, I>> s;
public:
	/* time: O(1), space: O(1) auxiliary (i.e. does not count stack itself) */
	NestedIterator(const vector<NestedInteger> &nestedList) {
		s.emplace(nestedList.begin(), nestedList.end());
	}

	/* time: O(1) amortized, space: O(1) auxiliary (i.e. does not count stack itself) */
	int next() {
		if (!hasNext())
			return -1; /* failed */
		return (s.top().first++)->getInteger();
	}

	/* time: O(1) amortized, space: O(1) auxiliary (i.e. does not count stack itself) */
	bool hasNext() {
		while (!s.empty()) {
			if (s.top().first == s.top().second) {
				s.pop();
			} else if (!s.top().first->isInteger()) {
				const auto& children = (s.top().first++)->getList();
				s.emplace(children.begin(), children.end());
			} else {
				return true;
			}
		}
		return false;
	}
};
