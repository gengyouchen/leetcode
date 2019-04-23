template <class K>
class OrderStatisticTree {
private:
	vector<K> keys;
	vector<int> BIT;
	static int lowbit(int x) { return x & -x; }
	int total = 0;
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
		++total;
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
	int size() const { return total; }
};

class Solution {
private:
	typedef long long K;
public:
	/* time: O(n*log(n)), space: O(n) */
	static int reversePairs(const vector<int>& nums) {
		const int n = nums.size();
		int ans = 0;
		OrderStatisticTree<K> ost(nums.begin(), nums.end());
		for (int num : nums)
			ans += ost.size() - ost.countSmaller(2 * (long long)num + 1), ost.insert(num);
		return ans;
	}
};
