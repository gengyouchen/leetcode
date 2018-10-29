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
	int select(int rank) const {
		int x = 1;
		while (x < segTree.size() / 2)
			if (rank <= segTree[x * 2])
				x = (x * 2);
			else
				rank -= segTree[x * 2], x = (x * 2 + 1);
		return x - segTree.size() / 2;
	}
	int count() const { return segTree[1]; }
	bool empty() const { return segTree[1] == 0; }
};

class Solution {
public:
	/* time: O(n*log(n)), space: O(n) */
	string getPermutation(int n, int k) {
		--k; /* convert to zero-based numbering */

		OrderStatisticTree choices(n + 1, true);
		choices.modify(0, false);

		int nPermutation = 1;
		for (int i = 2; i <= n; ++i)
			nPermutation *= i;

		string ans;
		while (!choices.empty()) {
			nPermutation /= choices.count();

			const int num = choices.select(1 + k / nPermutation);
			ans.push_back('0' + num);
			choices.modify(num, false);

			k %= nPermutation;
		}
		return ans;
	}
};
