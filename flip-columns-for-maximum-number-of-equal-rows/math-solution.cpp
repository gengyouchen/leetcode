class Trie {
private:
	Trie* next[2] = {};
	int size = 0;
public:
	void insert(const vector<int>& row) {
		auto p = this;
		for (int col : row) {
			if (!p->next[col])
				p->next[col] = new Trie();
			++p->size, p = p->next[col];
		}
		++p->size;
	}
	int count(const vector<int>& row, bool complement = false) const {
		auto p = this;
		for (int col : row) {
			if (complement)
				col = 1 - col;
			if (!p->next[col])
				return 0;
			p = p->next[col];
		}
		return p->size;
	}
};

class Solution {
public:
	/* time: O(n^2), space: O(n^2) */
	static int maxEqualRowsAfterFlips(const vector<vector<int>>& matrix) {
		/*
		 * Key Observation:
		 * If row[i] != row[j] initially,
		 * then no matter how many columns we've flipped, row[i] != row[j].
		 *
		 * Therefore, when row[i] becomes all values 0,
		 * (1) row[a] becomes all values 0 IFF row[i] == row[a] initially
		 * (2) row[b] becomes all values 1 IFF row[i] == ~row[b] initially
		 */
		Trie dict;
		int ans = 0;
		for (const auto& row : matrix)
			dict.insert(row), ans = max(ans, dict.count(row) + dict.count(row, true));
		return ans;
	}
};
