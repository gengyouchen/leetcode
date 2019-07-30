class MovingAverage {
private:
	queue<int> q;
	int k;
	long long sum = 0;
public:
	/* time: O(1), space: O(1) */
	MovingAverage(int size) : k(size) {}

	/* time: O(1), space: O(1) auxiliary (i.e. does not count queue itself) */
	double next(int val) {
		if (!k)
			return -1; /* failed */
		sum += val, q.push(val);
		if (q.size() > k)
			sum -= q.front(), q.pop();
		return (double)sum / q.size();
	}
};
