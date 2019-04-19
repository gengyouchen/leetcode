class OrderStatisticTree {
private:
	vector<int> segTree;
public:
	OrderStatisticTree(int n, bool present) {
		int nLeaf = 1;
		while (nLeaf < n)
			nLeaf *= 2;
		segTree.resize(nLeaf);
		segTree.resize(nLeaf + n, present ? 1 : 0);
		segTree.resize(nLeaf * 2, 0);
		for (int x = nLeaf - 1; x; --x)
			segTree[x] = segTree[x * 2] + segTree[x * 2 + 1];
	}
	void modify(int x, bool present) {
		x += segTree.size() / 2;
		segTree[x] = present ? 1 : 0;
		while (x /= 2)
			segTree[x] = segTree[x * 2] + segTree[x * 2 + 1];
	}
	int rank(int x) const {
		int count = 0;
		x += segTree.size() / 2;
		while (x) {
			if (x % 2)
				count += segTree[x - 1];
			x /= 2;
		}
		return count;
	}
};

class Solution {
public:
	/* time: O(n*log(n)), space: O(n) */
	static vector<int> countSmaller(const vector<int>& nums) {
		const int n = nums.size();
		vector<pair<int, int>> A;
		for (int i = 0; i < n; ++i)
			A.emplace_back(nums[i], i);
		sort(A.begin(), A.end());
		for (int i = 0; i < n; ++i)
			A[i].first = A[i].second, A[i].second = i;
		sort(A.begin(), A.end());

		vector<int> ans(n);
		OrderStatisticTree ost(n, false);
		for (int i = n - 1; i >= 0; --i)
			ans[i] = ost.rank(A[i].second), ost.modify(A[i].second, true);
		return ans;
	}
};
