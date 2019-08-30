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
	int CountSet() const { return nSet; };
};

class Solution {
public:
	/*
	 * time: O(n^2 * alpha(n^2)) ~= O(n^2), space: O(n),
	 * where alpha(x) is the inverse Ackermann function.
	 *
	 * Because alpha(x) < 5 for any value x that can be written in this physical universe,
	 * all the disjoint-set operations take place in essentially constant time.
	 */
	static int findCircleNum(const vector<vector<int>>& M) {
		const int n = M.size();
		DisjointSet ds(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (M[i][j])
					ds.Union(i, j);
			}
		}
		return ds.CountSet();
	}
};
