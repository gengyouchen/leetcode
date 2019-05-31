class NumArray {
private:
	vector<int> BIT;
	static int lowbit(int x) { return x & -x; }
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count Fenwick tree itself) */
	NumArray(const vector<int>& nums) {
		BIT.resize(nums.size() + 1);
		for (int x = 1; x < BIT.size(); ++x) {
			BIT[x] += nums[x - 1];
			if (x + lowbit(x) < BIT.size())
				BIT[x + lowbit(x)] += BIT[x];
		}
	}
	/* time: O(log(n)), space: O(1) auxiliary (i.e. does not count Fenwick tree itself) */
	void update(int i, int val) {
		const int diff = val - sumRange(i, i);
		for (int x = 1 + i; x < BIT.size(); x += lowbit(x))
			BIT[x] += diff;
	}
	/* time: O(log(n)), space: O(1) auxiliary (i.e. does not count Fenwick tree itself) */
	int sumRange(int i, int j) const {
		int sum = 0;
		for (int x = 1 + j; x > 0; x -= lowbit(x))
			sum += BIT[x];
		for (int x = i; x > 0; x -= lowbit(x))
			sum -= BIT[x];
		return sum;
	}
};
