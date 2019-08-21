class Trie {
private:
	Trie* child[2] = {};
public:
	void insert(int num) {
		Trie *p = this;
		for (int d = 31; d >= 0; --d) {
			const int mask = 1 << d;
			const int key = (num & mask) ? 1 : 0;
			if (!p->child[key])
				p->child[key] = new Trie();
			p = p->child[key];
		}
	}
	int maxXorWith(int num) const {
		int ret = 0;
		const Trie *p = this;
		for (int d = 31; d >= 0; --d) {
			const int mask = 1 << d;
			const int key = (num & mask) ? 1 : 0;
			if (p->child[1 - key])
				ret |= mask, p = p->child[1 - key];
			else
				p = p->child[key];
		}
		return ret;
	}
};

class Solution {
public:
	/* time: O(n), space: O(n) */
	static int findMaximumXOR(const vector<int>& nums) {
		int ans = 0;
		Trie dict;
		for (int num : nums)
			dict.insert(num), ans = max(ans, dict.maxXorWith(num));
		return ans;
	}
};
