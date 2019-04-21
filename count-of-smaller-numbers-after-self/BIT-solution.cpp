class OrderStatisticTree {
private:
	vector<int> BIT;
	static int lowbit(int x) { return x & -x; }
public:
	OrderStatisticTree(int n) : BIT(n + 1) {}
	void insert(int x) {
		for (int i = x + 1; i < BIT.size(); i += lowbit(i))
			BIT[i] += 1;
	}
	int rank(int x) const {
		int count = 0;
		for (int i = x + 1; i > 0; i -= lowbit(i))
			count += BIT[i];
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
