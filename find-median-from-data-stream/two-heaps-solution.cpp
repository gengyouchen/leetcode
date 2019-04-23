class MedianFinder {
private:
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;
	int bf() const { return (int)right.size() - (int)left.size(); }
public:
	/* time: O(1), space: O(1) auxiliary (i.e. does not count two heap itself) */
	MedianFinder() {}

	/* time: O(log(n)), space: O(1) auxiliary (i.e. does not count two heap itself) */
	void addNum(int num) {
		if (left.empty() || left.top() >= num) {
			left.push(num);
			if (bf() < -1)
				right.push(left.top()), left.pop();
		} else {
			right.push(num);
			if (bf() > 1)
				left.push(right.top()), right.pop();
		}
	}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count two heap itself) */
	double findMedian() const {
		if (bf() > 0)
			return right.top();
		if (bf() < 0)
			return left.top();
		return ((double)left.top() + (double)right.top()) / 2;
	}
};
