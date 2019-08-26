class DisjointSet {
private:
	vector<int> p, rank;
	int nSet;
public:
	DisjointSet(int n) : p(n), rank(n), nSet(n) {
		iota(p.begin(), p.end(), 0);
	}
	int FindSet(int x) {
		if (p[x] != x)
			p[x] = FindSet(p[x]);
		return p[x];
	}
	void Union(int x, int y) {
		x = FindSet(x), y = FindSet(y);
		if (x != y) {
			--nSet;
			if (rank[x] > rank[y]) {
				p[y] = x;
			} else {
				p[x] = y;
				if (rank[x] == rank[y])
					++rank[y];
			}
		}
	}
	int CountSet() const {
		return nSet;
	};
};

class Solution {
public:
	/*
	 * time: O(n * alpha(n)) ~= O(n), space: O(n),
	 * where alpha(x) is the inverse Ackermann function.
	 *
	 * Because alpha(x) < 5 for any value x that can be written in this physical universe,
	 * all the disjoint-set operations take place in essentially constant time.
	 */
	static int removeStones(const vector<vector<int>>& stones) {
		const int n = stones.size();
		unordered_map<int, vector<int>> row2indices, col2indices;
		for (int i = 0; i < n; ++i) {
			const int row = stones[i][0], col = stones[i][1];
			row2indices[row].push_back(i), col2indices[col].push_back(i);
		}

		DisjointSet ds(n);
		for (const auto& it : row2indices) {
			const auto& indices = it.second;
			for (int i = 1; i < indices.size(); ++i)
				ds.Union(indices[i], indices[i - 1]);
		}
		for (const auto& it : col2indices) {
			const auto& indices = it.second;
			for (int i = 1; i < indices.size(); ++i)
				ds.Union(indices[i], indices[i - 1]);
		}
		return n - ds.CountSet();
	}
};
