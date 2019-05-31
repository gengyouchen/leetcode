class NumArray {
private:
	vector<int> segTree;
public:
	/* time: O(n), space: O(1) auxiliary (i.e. does not count segment tree itself) */
	NumArray(const vector<int>& nums) {
		int nLeaf = 1;
		while (nLeaf < nums.size())
			nLeaf *= 2;
		segTree.resize(nLeaf * 2);
		copy(nums.begin(), nums.end(), segTree.begin() + nLeaf);
		for (int x = nLeaf - 1; x; --x)
			segTree[x] = segTree[x * 2] + segTree[x * 2 + 1];
	}
	/* time: O(log(n)), space: O(1) auxiliary (i.e. does not count segment tree itself) */
	void update(int i, int val) {
		int x = segTree.size() / 2 + i;
		segTree[x] = val;
		while (x /= 2)
			segTree[x] = segTree[x * 2] + segTree[x * 2 + 1];
	}
	/* time: O(log(n)), space: O(1) auxiliary (i.e. does not count segment tree itself) */
	int sumRange(int i, int j) const {
		int x = segTree.size() / 2 + i, y = segTree.size() / 2 + j;
		if (x == y)
			return segTree[x];
		int sum = segTree[x] + segTree[y];
		while (x / 2 != y / 2) {
			if (!(x % 2))
				sum += segTree[x + 1];
			if (y % 2)
				sum += segTree[y - 1];
			x /= 2, y /= 2;
		}
		return sum;
	}
};
