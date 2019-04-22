template <class K>
class OrderStatisticTree {
private:
	unordered_map<K, int> key2leaf;
	vector<int> segTree;
public:
	template <class I>
	OrderStatisticTree(I first, I last) {
		vector<K> keys(first, last);
		sort(keys.begin(), keys.end());
		int nLeaf = 1;
		while (nLeaf < keys.size())
			nLeaf *= 2;
		segTree.resize(nLeaf * 2, 0);
		int x = nLeaf;
		for (const auto& key : keys)
			key2leaf[key] = x++;
	}
	void insert(const K& key) {
		auto it = key2leaf.find(key);
		assert(it != key2leaf.end());
		for (int x = it->second; x > 0; x /= 2)
			++segTree[x];
	}
	int rank(const K& key) const {
		int ranking = 1;
		auto it = key2leaf.find(key);
		assert(it != key2leaf.end());
		for (int x = it->second; x > 1; x /= 2) {
			if (x % 2)
				ranking += segTree[x - 1];
		}
		return ranking;
	}
};

class Solution {
private:
	typedef long long K;
public:
	/* time: O(n*log(n)), space: O(n) */
	static vector<int> countSmaller(const vector<int>& nums) {
		const int n = nums.size();
		vector<int> ans(n);
		OrderStatisticTree<K> ost(nums.begin(), nums.end());
		for (int i = n - 1; i >= 0; --i)
			ans[i] = ost.rank(nums[i]) - 1, ost.insert(nums[i]);
		return ans;
	}
};
