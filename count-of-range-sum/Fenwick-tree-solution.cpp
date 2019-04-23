template <class K>
class OrderStatisticTree {
private:
	vector<K> keys;
	vector<int> BIT;
	static int lowbit(int x) { return x & -x; }
public:
	template <class I>
	OrderStatisticTree(I first, I last) {
		unordered_set<K> S(first, last);
		vector<K> A(S.begin(), S.end());
		sort(A.begin(), A.end()), keys = move(A), BIT.resize(keys.size() + 1, 0);
	}
	void insert(const K& key) {
		const auto it = lower_bound(keys.begin(), keys.end(), key);
		assert(it != keys.end() && *it == key);
		for (int x = 1 + distance(keys.begin(), it); x < BIT.size(); x += lowbit(x))
			++BIT[x];
	}
	int countSmaller(const K& target) const {
		int count = 0;
		const auto it = lower_bound(keys.begin(), keys.end(), target);
		if (it != keys.begin()) {
			for (int x = 1 + distance(keys.begin(), it - 1); x > 0; x -= lowbit(x))
				count += BIT[x];
		}
		return count;
	}
};

class Solution {
private:
	typedef long long K;
public:
	/* time: O(n*log(n)), space: O(n) */
	static int countRangeSum(const vector<int>& nums, int lower, int upper) {
		const int n = nums.size();
		vector<K> S(n + 1);
		for (int i = 1; i <= n; ++i)
			S[i] = S[i - 1] + nums[i - 1];

		int ans = 0;
		OrderStatisticTree<K> ost(S.begin(), S.end());
		for (const auto& s : S)
			ans += ost.countSmaller(s - lower + 1) - ost.countSmaller(s - upper), ost.insert(s);
		return ans;
	}
};
