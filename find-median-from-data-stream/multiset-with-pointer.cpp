class MedianFinder {
private:
	multiset<int> keys;
	multiset<int>::iterator mid;
public:
	/* time: O(1), space: O(1) auxiliary (i.e. does not count tree itself) */
	MedianFinder() {}

	/* time: O(log(n)), space: O(1) auxiliary (i.e. does not count tree itself) */
	void addNum(int num) {
		const int n = keys.size();
		keys.insert(num);
		if (!n) {
			mid = keys.begin();
		} else if (n % 2) {
			if (num < *mid)
				--mid;
		} else {
			if (num >= *mid)
				++mid;
		}
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count tree itself) */
	double findMedian() {
		const int n = keys.size();
		if (n % 2)
			return *mid;
		return ((double)*mid + (double)*next(mid)) / 2;
	}
};
