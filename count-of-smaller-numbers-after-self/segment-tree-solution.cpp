class OrderStatisticTree {
private:
	vector<int> segTree;
public:
	OrderStatisticTree(int n) {
		int nLeaf = 1;
		while (nLeaf < n)
			nLeaf *= 2;
		segTree.resize(nLeaf * 2, 0);
	}
	void insert(int x) {
		for (int i = x + segTree.size() / 2; i > 0; i /= 2)
			segTree[i] += 1;
	}
	int rank(int x) const {
		int count = 0;
		for (int i = x + segTree.size() / 2; i > 0; i /= 2) {
			if (i % 2)
				count += segTree[i - 1];
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
		OrderStatisticTree ost(n);
		for (int i = n - 1; i >= 0; --i)
			ans[i] = ost.rank(A[i].second), ost.insert(A[i].second);
		return ans;
	}
};
