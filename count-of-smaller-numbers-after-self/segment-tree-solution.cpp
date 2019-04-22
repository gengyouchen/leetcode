template <class K>
class OrderStatisticTree {
private:
	map<K, int> key2leaf;
	vector<int> segTree;
public:
	template <class I>
	OrderStatisticTree(I first, I last) {
		for (auto it = first; it != last; ++it)
			key2leaf.emplace(*it, 0);
		int nLeaf = 1;
		while (nLeaf < key2leaf.size())
			nLeaf *= 2;
		segTree.resize(nLeaf * 2, 0);
		int x = nLeaf;
		for (auto& ii : key2leaf)
			ii.second = x++;
	}
	void insert(const K& key) {
		auto it = key2leaf.find(key);
		assert(it != key2leaf.end());
		for (int x = it->second; x > 0; x /= 2)
			++segTree[x];
	}
	int rank(const K& target) const {
		int ranking = 1;
		auto it = key2leaf.lower_bound(target);
		if (it != key2leaf.begin()) {
			--it, ranking += segTree[it->second];
			for (int x = it->second; x > 1; x /= 2) {
				if (x % 2)
					ranking += segTree[x - 1];
			}
		}
		return ranking;
	}
};

class Solution {
public:
	/* time: O(n*log(n)), space: O(n) */
	static vector<int> countSmaller(const vector<int>& nums) {
		const int n = nums.size();
		vector<int> ans(n);
		OrderStatisticTree<int> ost(nums.begin(), nums.end());
		for (int i = n - 1; i >= 0; --i)
			ans[i] = ost.rank(nums[i]) - 1, ost.insert(nums[i]);
		return ans;
	}
};
