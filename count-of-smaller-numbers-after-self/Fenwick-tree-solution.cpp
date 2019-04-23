template <class K>
class OrderStatisticTree {
private:
	unordered_map<K, int> key2leaf;
	vector<int> BIT;
	static int lowbit(int x) { return x & -x; }
public:
	template <class I>
	OrderStatisticTree(I first, I last) {
		for (auto it = first; it != last; ++it)
			key2leaf.emplace(*it, 0);
		const int n = key2leaf.size();

		vector<K> keys(n);
		auto getKey = [](const auto& ii) { return ii.first; };
		transform(key2leaf.begin(), key2leaf.end(), keys.begin(), getKey);
		sort(keys.begin(), keys.end());

		BIT.resize(n + 1, 0);
		int x = 1;
		for (const auto& key : keys)
			key2leaf[key] = x++;
	}
	void insert(const K& key) {
		auto it = key2leaf.find(key);
		assert(it != key2leaf.end());
		for (int x = it->second; x < BIT.size(); x += lowbit(x))
			++BIT[x];
	}
	int countSmaller(const K& key) const {
		int count = 0;
		auto it = key2leaf.find(key);
		assert(it != key2leaf.end());
		for (int x = it->second - 1; x > 0; x -= lowbit(x))
			count += BIT[x];
		return count;
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
			ans[i] = ost.countSmaller(nums[i]), ost.insert(nums[i]);
		return ans;
	}
};
