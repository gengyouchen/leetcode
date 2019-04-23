template <class K>
class OrderStatisticTree {
private:
	vector<K> keys;
	vector<int> segTree;
public:
	template <class I>
	OrderStatisticTree(I first, I last) {
		unordered_set<K> S(first, last);
		vector<K> A(S.begin(), S.end());
		sort(A.begin(), A.end()), keys = move(A);
		int nLeaf = 1;
		while (nLeaf < keys.size())
			nLeaf *= 2;
		segTree.resize(nLeaf * 2, 0);
	}
	void insert(const K& key) {
		const auto it = lower_bound(keys.begin(), keys.end(), key);
		assert(it != keys.end() && *it == key);
		int x = segTree.size() / 2 + distance(keys.begin(), it);
		while (x > 0)
			++segTree[x], x /= 2;
	}
	int countSmaller(const K& target) const {
		int count = 0;
		const auto it = lower_bound(keys.begin(), keys.end(), target);
		if (it != keys.begin()) {
			int x = segTree.size() / 2 + distance(keys.begin(), it - 1);
			count += segTree[x];
			while (x > 1) {
				if (x % 2)
					count += segTree[x - 1];
				x /= 2;
			}
		}
		return count;
	}
	int size() const { return segTree[1]; }
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
